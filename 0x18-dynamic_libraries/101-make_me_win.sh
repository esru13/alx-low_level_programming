#!/bin/bash
wget -P /tmp https://raw.githubusercontent.com/eyasuyid/alx-low_level_programming/main/0x18-dynamic_libraries/libmask.so
export LD_PRELOAD=/tmp/libmask.so
