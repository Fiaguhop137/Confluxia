#!/bin/bash
set -e
g++ -std=c++17 ./assets/src/bundler.cpp -o ./assets/data/bundler
./assets/data/bundler
cosmoc++ -std=c++23 -O3 -g -Wall -Wextra -Wpedantic -Wshadow -Wconversion -fdiagnostics-color=always ./assets/src/confluxia.cpp -o ./tmp
rm -f ./assets/data/bundler
rm -f ./tmp.aarch64.elf
rm -f ./tmp.com.dbg
mv ./tmp ./Confluxia.exe
nohup git sync > /dev/null 2>&1 &