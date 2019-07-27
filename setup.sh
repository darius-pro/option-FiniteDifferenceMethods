#!/bin/sh

export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:$PWD/include

g++ src/main.cpp
