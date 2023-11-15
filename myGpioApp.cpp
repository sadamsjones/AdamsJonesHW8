//myGpioApp.cpp is an application that instantiates MYGPIO class and creates the following objects and carries out the following operations

#include "myGpio.h"
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

int main() {
    // Instantiate an object as an output gpio using pin p9.12
    MYGPIO outputGPIO(60);
    outputGPIO.setDirection(OUTPUT);

    // Instantiate an object as an input gpio using pin p8.16
    MYGPIO inputGPIO(46);
    inputGPIO.setDirection(INPUT);

    // Set p9.12 high for 3 seconds, and then set it low. Print out its value in both cases.
    outputGPIO.setValue(HIGH);
    cout << "Value of p9.12: " << outputGPIO.getValue() << endl;
    sleep(3);
    outputGPIO.setValue(LOW);
    cout << "Value of p9.12: " << outputGPIO.getValue() << endl;

    // Read p8.16 and print out its value
    cout << "Value of p8.16: " << inputGPIO.getValue() << endl;

    return 0;
}
