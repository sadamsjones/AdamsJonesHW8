#!/bin/bash
#bash build script for gpioApp.cpp
#Compiler and flags
CC=g++
CFLAGS=-Wall
# Source file and output executable
SOURCE=gpioApp.cpp
OUTPUT=gpioApp
# Build the application
$CC $SOURCE -o $OUTPUT $CFLAGS
# Configuration for P9.12 = GPIO_60
config-pin P9_12 gpio
# Configuration for P8.16 = GPIO_46
config-pin P8_16 gpio
# Example invocation
# ./gpioApp
