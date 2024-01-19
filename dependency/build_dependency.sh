#!/bin/bash
#
# ubuntu dep
sudo apt install libx11-dev libxrendr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev

# get GLM
# -----------------------------------------------------
TARGET="glm"
git clone -b 0.9.9.8 https://github.com/g-truc/glm.git $TARGET
rm -rf $TARGET/.git

# build GLAD     # https://github.com/Dav1dde/glad
# -----------------------------------------------------
# TODO: change to Curl or Wget or Forked Repo!
TARGET="glad"
cmake -S ./glad -B ./glad/build && make -C ./glad/build

# build GLFW      # https://github.com/glfw/glfw
# -----------------------------------------------------
# TODO: change to Curl or Wget or Forked Repo!
TARGET="glfw"
cmake -S ./glfw -B ./glfw/build && make -C ./glfw/build


