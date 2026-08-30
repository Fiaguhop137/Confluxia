#!/bin/bash
set -e
g++ -std=c++17 assets/bundler.cpp
./a.out
cosmoc++ -std=c++23 -O3 -g -Wall -Wextra -Wpedantic -Wshadow -Wconversion -fdiagnostics-color=always confluxia.cpp -o confluxia
nohup git sync > /dev/null 2>&1 &
rm -f a.out
rm -f confluxia.aarch64.elf
rm -f confluxia.com.dbg