# 复合机器人导航及抓取
实现一种复合机器人(底盘麦轮AGV+四自由度机械臂)对未知地形建图,并实现对地形房间内盒子进行3D检测和空间抓取

还包括基于AR标签实现对3D标签的定位

## 环境依赖

1.ros1 Melodic/noetic

2.pcl 

3.gazebo

## 使用步骤



1. 安装ROS.
   Melodic/Ubuntu 18.04 [安装步骤](http://wiki.ros.org/melodicic/Installation/Ubuntu)
2. 配置好开发环境. [配置方法](http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment)
3. 获取源码:

```
cd ~/catkin_ws/src/
git clone https://github.com/wk1215/wmani_ros.git
```

1. 安装依赖项:

```
cd ~/catkin_ws/src/wpb_mani/wpb_mani_bringup/scripts
./install_for_melodic.sh
```

 (2)noetic版本

```
cd ~/catkin_ws/src/wpb_mani/wpb_mani_bringup/scripts
./install_for_noetic.sh
```



1. 编译

```
cd ~/catkin_ws
catkin_make
```

## Usage
1. gmapping建图操作:
```bash
source devel/setup.bash
roslaunch wpb_mani_simulator gmapping.launch
```
2. 导航任务:

```
source devel/setup.bash
roslaunch wpb_mani_simulator navigation.launch
```

3. 机械臂抓取任务:

```bash
source devel/setup.bash
roslaunch wpb_mani_simulator grab_box.launch
```
4. 全任务:

```bash
source devel/setup.bash
roslaunch wpb_mani_simulator map_tools.launch
//移动到合适位置
rosrun wpb_mani_tutorials  wpb_mani_grab_demo
```

*** 
