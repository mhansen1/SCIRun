#!/usr/bin/env bash

sudo apt-get install -qq cmake
sudo apt-get install -qq libosmesa6-dev
sudo apt-get install -qq libqt4-dev qt4-qmake
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.9
echo "$CXX"
if [ "$CXX" = "g++" ]; then sudo apt-get install -qq g++-4.9; fi
if [ "$CXX" = "g++" ]; then export CXX="g++-4.9" CC="gcc-4.9"; fi
