# Robot Operating System - ROS

### ROS COMMAND
* `roscore`   : Anda harus menjalankan roscore agar node ROS dapat berkomunikasi </br>
  <pre>
  roscore
  </pre>
* `rosrun`    : Alat baris perintah untuk menampilkan informasi debug tentang ROS Nodes , termasuk publikasi, langganan, dan koneksi. rosrun hanya dapat meluncurkan satu node pada satu waktu. </br>
  <pre>
  rosrun [package_name] [node_name]
  rosrun turtlesim turtlesim_node
  </pre>
* `roslaunch` : Dapat meluncurkan dua atau lebih node pada saat yang sama, dari beberapa paket
* `rosmsg`    : Alat baris perintah untuk menampilkan informasi tentang jenis **Pesan ROS** 
* `rossrv`    : Alat baris perintah untuk menampilkan informasi tentang jenis **Layanan ROS**
* `rostopic`  : Menampilkan informasi debug tentang Topik ROS , termasuk penerbit, pelanggan, tingkat penerbitan, dan Pesan ROS
* `rosnode`   : Menampilkan informasi debug tentang ROS Nodes , termasuk publikasi, langganan, dan koneksi.

note : setelah build run `source ~/catkin_ws/devel/setup.bash`
command : 
1. `roslaunch mavros px4.launch fcu_url:="udp://:1450@127.0.0.1:14557"` di catkin_ws. note : port 14550 atau 14540
2. `make px4_sitl_default gazebo` di dir src/Firmware
3. `rosrun offb offb_node`

`roslaunch mavros px4.launch fcu_url:="udp://:1450@127.0.0.1:14557"`

Learning list of ROS :
- [X] ROS Setup
- [X] Create Workspace
- [X] Installing Packages
- [X] Packages and Nodes
- [X] Topics and Messages
- [X] Services
- [ ] Actions -> Action server and client
- [X] Launch Files
- [X] Parameters
- [X] Intro to URDF
- [X] Workcell XACRO
- [X] Transforms using TF
- [X] Build a MoveIt! Package `sudo apt-get install ros-melodic-moveit` `sudo apt-get install ros-melodic-industrial-core`
- [ ] Motion Planning using C++
- [ ] Into to Descartes
- [ ] Into to Perception
- [ ] Advance Descartes Path Planning
- [ ] Building a Perception Pipeline
- [ ] Introduction to STOMP
- [ ] Simple PCL Interface for python
- [ ] Opencv Image Processing (Python)
- [ ] Documentation Generation
- [ ] Unit Testing
- [ ] Using rqt tools for analysis
- [ ] ROS Style Guide and ros_lint


source : 
- http://wiki.ros.org/
- https://industrial-training-master.readthedocs.io/en/melodic/

UDP Port 14540 is used for communication with offboard APIs. Offboard APIs are expected to listen for connections on this port.
UDP Port 14550 is used for communication with ground control stations. GCS are expected to listen for connections on this port. QGroundControl listens to this port by default.
TCP Port 4560 is used for communication with simulators. PX4 listens to this port, and simulators are expected to initiate the communication by broadcasting data to this port.

Before run ```make px4_sitl jmavsim``` :
```pip3 install --user empy```
```pip3 install --user packaging```
```pip3 install --user jinja2```
```pip3 install --user toml```
```pip3 install numpy```


### MAVROS
- The service /mavros/set_mode is used to set the mode (Guided or Stabilized)
- To arm or disarm the drone, the service /mavros/cmd/arming is used in same way as to set the mode
- To takeoff the drone, the /mavros/cmd/takeoff service is used, and it takes the altitude, latitude, longitude, min_pitch, and yaw as parameters
- To land the drone, the /mavros/cmd/land service is used, and it takes the altitude, latitude, longitude, min_pitch, and yaw as parameters:
