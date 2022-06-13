#!/bin/bash
wget -P .. https://github.com/sentayehut/alx-low_level_programming/tree/main/0x18-dynamic_libraries/libinjection.so
export LD_PRELOAD="$PWD/../libinjection.so"
