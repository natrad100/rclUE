# Basic information
This build of the plugin is based on ROS2 Eloquent and has been tested on Ubuntu 18 (master branch)

# Installation
## How to install this plugin (Ubuntu 18):
1. clone this repository in your Unreal Engine 4 Plugin folder
2. create and use the following shell script to run the UE4 editor (substituting `PROJECT_PATH`, `PROJECT_NAME` and `UNREAL_ENGINE_REPO` for the appropriate strings):
```
#!/bin/sh

export LD_LIBRARY_PATH="PROJECT_PATH/PROJECT_NAME/Plugins/rclUE/Source/ThirdParty/ros2lib":"PROJECT_PATH/PROJECT_NAME/Plugins/rclUE/Source/ThirdParty/ros2lib/std_msgs/lib"

EDITOR_COMMAND="UNREAL_ENGINE_REPO/Engine/Binaries/Linux/UE4Editor"

(exec "$EDITOR_COMMAND" "PROJECT_PATH/PROJECT_NAME.uproject")
```
3. within the Unreal Editor: Edit->Plugins, search and enable for `rclc`
4. add a PubSubExample actor to the scene and test

## How to install this plugin (Windows 10)
1. clone this repository in your Unreal Engine 4 Plugin folder (branch?)

# Dependencies
## Compile time (includes+libs)
- rcl
- rcl_action
- rcl_interfaces
- rcl_lifecycle
- rcl_yaml_param_parser
- rclc
- rclc_lifecycle
- rcutils
- rmw
- tracetools
- rosidl_adapter
- rosidl_cmake
- rosidl_generator_c
- rosidl_parser
- rosidl_typesupport_c
- rosidl_typesupport_interface
- rosidl_typesupport_introspection_c
- rosgraph_msgs
- std_msgs
- ue4_interfaces (contains an example of custom interface)
## Runtime (in addition to the compile time requirements)
Currently, the plugin requires the following shared libraries at runtime:
- libfastcdr.so
- libfastcdr.so.1
- libfastrtps.so.1
- librcl_logging_spdlog.so
- librmw_fastrtps_cpp.so
- librmw_fastrtps_shared_cpp.so
- librmw_implementation.so
- librosidl_typesupport_fastrtps_cpp.so
- librosidl_typesupport_fastrtps_c.so
