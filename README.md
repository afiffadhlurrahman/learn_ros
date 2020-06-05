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
- [ ] Intro to URDF
- [ ] Workcell XACRO
- [ ] Transforms using TF
- [ ] Build a MoveIt! Package
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
