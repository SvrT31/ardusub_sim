Only of ROS Noetic! 

# The repository contains code to make ArduSub move using LQR controller

In order to compile this code, there are a few steps. I am assuming at this point that you have your pc on dual boot and have ROS Noetic along with Gazebo set up on it. (If not, please complete that first)

Once that is done, paste this code on terminal -
```
mkdir ardusub
cd ardusub
```

Then, git clone this repo or download and extract this repo in ardusub folder

Once you have successfully completed that, past this code on your terminal -
```
gedit ~/.bashrc
```

A text file named .bashrc will open. Add this code at the end of this text file -
```
source /usr/share/gazebo/setup.sh
source ~/ardusub/blue_ws/devel/setup.bash
export GAZEBO_MODEL_PATH=~/ardusub/ardupilot_gazebo/models
export GAZEBO_RESOURCE_PATH=~/ardusub/ardupilot_gazebo/worlds:${GAZEBO_RESOURCE_PATH}
export PATH=~/ardusub/ardupilot/Tools/autotest:$PATH
```

