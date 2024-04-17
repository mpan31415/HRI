from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

from cpp_pubsub.exp_params import *

import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():

    ###### franka_bringup franka.launch.py parameters ######
    robot_ip_parameter_name = 'robot_ip'
    load_gripper_parameter_name = 'load_gripper'
    use_fake_hardware_parameter_name = 'use_fake_hardware'
    fake_sensor_commands_parameter_name = 'fake_sensor_commands'
    use_rviz_parameter_name = 'use_rviz'

    robot_ip = LaunchConfiguration(robot_ip_parameter_name)
    load_gripper = LaunchConfiguration(load_gripper_parameter_name)
    use_fake_hardware = LaunchConfiguration(use_fake_hardware_parameter_name)
    fake_sensor_commands = LaunchConfiguration(fake_sensor_commands_parameter_name)
    use_rviz = LaunchConfiguration(use_rviz_parameter_name)


    ###### my own launch arguments ######
    free_drive_parameter_name = 'free_drive'
    mapping_ratio_parameter_name = 'mapping_ratio'
    use_depth_parameter_name = 'use_depth'
    participant_parameter_name = 'part_id'
    alpha_parameter_name = 'alpha_id'
    trajectory_parameter_name = 'traj_id'

    free_drive = LaunchConfiguration(free_drive_parameter_name)
    mapping_ratio = LaunchConfiguration(mapping_ratio_parameter_name)
    use_depth = LaunchConfiguration(use_depth_parameter_name)
    participant = LaunchConfiguration(participant_parameter_name)
    alpha = LaunchConfiguration(alpha_parameter_name)
    trajectory = LaunchConfiguration(trajectory_parameter_name)


    # rviz_file = os.path.join(get_package_share_directory('franka_description'), 'rviz',
    #                          'my_config.rviz')
    # rviz_file = os.path.join(get_package_share_directory('franka_description'), 'rviz',
    #                          'autonomy_fitts.rviz')
    rviz_file = os.path.join(get_package_share_directory('franka_description'), 'rviz',
                             'autonomy_cl_trust.rviz')


    return LaunchDescription([
        
        ###### franka_bringup franka.launch.py parameters ######
        DeclareLaunchArgument(
            robot_ip_parameter_name,
            default_value='172.16.0.2',                 ### originally this line was not here
            description='Hostname or IP address of the robot.'),
        DeclareLaunchArgument(
            use_rviz_parameter_name,
            default_value='false',                       ### we actually are using Rviz, just not launching through franka.launch.py (franka_bringup)
            description='Visualize the robot in Rviz'),
        DeclareLaunchArgument(
            use_fake_hardware_parameter_name,
            default_value='false',
            description='Use fake hardware'),
        DeclareLaunchArgument(
            fake_sensor_commands_parameter_name,
            default_value='false',
            description="Fake sensor commands. Only valid when '{}' is true".format(
                use_fake_hardware_parameter_name)),
        DeclareLaunchArgument(
            load_gripper_parameter_name,
            default_value='true',
            description='Use Franka Gripper as an end-effector, otherwise, the robot is loaded '
                        'without an end-effector.'),


        ###### my experimental config (using launch arguments) ######
        # DeclareLaunchArgument(
        #     free_drive_parameter_name,
        #     default_value='0',
        #     description='Free drive parameter'),
        # DeclareLaunchArgument(
        #     mapping_ratio_parameter_name,
        #     default_value='3.0',  
        #     description='Mapping ratio parameter'),
        # DeclareLaunchArgument(
        #     participant_parameter_name,
        #     default_value='0',  
        #     description='Participant ID parameter'),
        # DeclareLaunchArgument(
        #     autonomy_parameter_name,
        #     default_value='0',
        #     description='Autonomy ID parameter'),
        # DeclareLaunchArgument(
        #     trajectory_parameter_name,
        #     default_value='0',
        #     description='Trajectory ID parameter'),

        DeclareLaunchArgument(
            free_drive_parameter_name,
            default_value=my_free_drive,
            description='Free drive parameter'),
        DeclareLaunchArgument(
            mapping_ratio_parameter_name,
            default_value=my_mapping_ratio,  
            description='Mapping ratio parameter'),
        DeclareLaunchArgument(
            use_depth_parameter_name,
            default_value=my_use_depth,  
            description='Use depth parameter'),
        DeclareLaunchArgument(
            participant_parameter_name,
            default_value=my_part_id,  
            description='Participant ID parameter'),
        DeclareLaunchArgument(
            alpha_parameter_name,
            default_value=my_alpha_id,
            description='Alpha ID parameter'),
        DeclareLaunchArgument(
            trajectory_parameter_name,
            default_value=my_traj_id,
            description='Trajectory ID parameter'),


        ### franka_bringup launch ###
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([PathJoinSubstitution(
                [FindPackageShare('franka_bringup'), 'launch', 'franka.launch.py'])]),
            launch_arguments={robot_ip_parameter_name: robot_ip,
                              load_gripper_parameter_name: load_gripper,
                              use_fake_hardware_parameter_name: use_fake_hardware,
                              fake_sensor_commands_parameter_name: fake_sensor_commands,
                              use_rviz_parameter_name: use_rviz
                              }.items(),
        ),


        ############################## THE FOLLOWING ARE MY OWN STUFF ##############################

        Node(package='rviz2',
             executable='rviz2',
             name='rviz2',
             arguments=['--display-config', rviz_file]
             ),

        # joint trajectory controller
        # Node(
        #     package='controller_manager',
        #     executable='spawner',
        #     arguments=['joint_trajectory_controller'],
        #     output='screen',
        # ),

        # my controller
        Node(
            package='controller_manager',
            executable='spawner',
            arguments=['my_controller'],
            output='screen',
        ),

        ### kinect_camera launch ### 
        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource([PathJoinSubstitution(
        #         [FindPackageShare('azure_kinect_ros_driver'), 'launch', 'driver.launch.py'])])
        # ),

        # activate Falcon node [need Falcon to be connected]
        Node(
            package='cpp_pubsub',
            executable='position_talker',
            parameters=[
                {mapping_ratio_parameter_name: mapping_ratio},
                {use_depth_parameter_name: use_depth},
                {participant_parameter_name: participant},
                {alpha_parameter_name: alpha},
                {trajectory_parameter_name: trajectory}
            ],
            output='screen',
            emulate_tty=True,
            name='position_talker'
        ),

        # marker publisher node
        Node(
            package='cpp_pubsub',
            executable='marker_publisher',
            parameters=[
                {use_depth_parameter_name: use_depth},
                {participant_parameter_name: participant},
                {alpha_parameter_name: alpha},
                {trajectory_parameter_name: trajectory}
            ],
            output='screen',
            emulate_tty=True,
            name='marker_publisher'
        ),

        # trajectory recorder node
        Node(
            package='cpp_pubsub',
            executable='traj_recorder.py',
            parameters=[
                {free_drive_parameter_name: free_drive},
                {mapping_ratio_parameter_name: mapping_ratio},
                {use_depth_parameter_name: use_depth},
                {participant_parameter_name: participant},
                {alpha_parameter_name: alpha},
                {trajectory_parameter_name: trajectory}
            ],
            output='screen',
            emulate_tty=True
        ),

        # publish {camera base frame, depth camera frame}
        Node(
            package='cpp_pubsub',
            executable='const_br',
            name='const_br'
        ),

        # publish recorded point cloud
        ExecuteProcess(
                cmd=[
                    "ros2",
                    "bag",
                    "play",
                    "/home/michael/bag_files/my_bag3",
                ],
                output="screen",
        )

    ])
