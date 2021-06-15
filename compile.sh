#!/bin/sh
mkdir -p bin/
gcc src/*.c -o "bin/$(gcc -dumpmachine).bin" `sdl2-config --cflags --static-libs`
