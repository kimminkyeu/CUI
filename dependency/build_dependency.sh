#!/bin/bash
#
# ubuntu dep
sudo apt install libx11-dev libxrendr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev

TARGET="glad"
cmake -S ./glad -B ./glad/build && make -C ./glad/build

TARGET="glfw"
cmake -S ./glfw -B ./glfw/build && make -C ./glfw/build

TARGET="spdlog"
git clone -b v1.11.0 https://github.com/gabime/spdlog.git $TARGET
rm -rf $TARGET/.git
cmake -S ./$TARGET -B ./$TARGET/build && make -C ./$TARGET/build -j

TARGET="glm"
git clone -b 0.9.9.8 https://github.com/g-truc/glm.git $TARGET
rm -rf $TARGET/.git
