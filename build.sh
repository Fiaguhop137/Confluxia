#!/bin/bash
g++ -std=c++23 -O3 -g -Wall -Wextra -Wpedantic -Wshadow -Wconversion -fdiagnostics-color=always confluxia.cpp -o confluxia
x86_64-w64-mingw32-g++ confluxia.cpp -o confluxia.exe
git sync