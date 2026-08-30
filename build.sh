#!/bin/bash
set -e
g++ -std=c++17 assets/bundler.cpp
./a.out
g++ -std=c++23 -O3 -g -Wall -Wextra -Wpedantic -Wshadow -Wconversion -fdiagnostics-color=always confluxia.cpp -o confluxia
x86_64-w64-mingw32-g++ -std=c++23 -O3 confluxia.cpp -o confluxia.exe
nohup git sync > /dev/null 2>&1 &
rm -f a.out