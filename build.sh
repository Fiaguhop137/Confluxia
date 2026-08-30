#!/bin/bash
g++ -std=c++23 -O3 -g -Wall -Wextra -Wpedantic -Wshadow -Wconversion -fdiagnostics-color=always confluxia.cpp -o confluxia
nohup x86_64-w64-mingw32-g++ confluxia.cpp -o confluxia.exe > /dev/null 2>&1 &
nohup git sync > /dev/null 2>&1 &