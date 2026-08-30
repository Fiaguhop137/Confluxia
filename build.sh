#!/bin/bash
set -e
g++ -std=c++17 assets/bundler.cpp -o assets/bundler
./assets/bundler
cosmoc++ -std=c++23 -O3 -g -Wall -Wextra -Wpedantic -Wshadow -Wconversion -fdiagnostics-color=always ./assets/confluxia.cpp -o confluxia
rm -f ./assets/bundler
rm -f ./confluxia.aarch64.elf
rm -f ./confluxia.com.dbg
mv ./confluxia ./Confluxia.exe
nohup git sync > /dev/null 2>&1 &