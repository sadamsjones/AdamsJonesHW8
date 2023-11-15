#!/bin/bash

#Bash Build dile for the myGpioApp.cpp aplication

g++ -c myGpio2.cpp -o myGpio2.o
g++ -c myGpioApp.cpp -o myGpioApp.o
g++ myGpio2.o myGpioApp.o -o myGpioApp


