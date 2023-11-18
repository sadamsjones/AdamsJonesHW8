//Application names gpioApp.cpp that uses Molloy's textbook's classes LED, GPIO, and the AnalogIn
class to control gpio pins.
//
#include "GPIO.h"
#include "LED.h"
#include "AnalogIn.h"
#include <iostream>
#include <fstream>
using namespace std;
int main() {
// Short description of the script
// Command line arguments: None
// Example invocation: ./gpioApp
// Task 1: Turn on user LEDs number 1 and 3
LED led1(1);
LED led3(3);
led1.turnOn();
led3.turnOn();
// Task 2: Flash user LED 2
LED led2(2);
led2.flash(1000);
// Task 3: Read the temperature sensor and display its value
AnalogIn tempSensor(46); // AnalogIn takes GPIO Input for P8.16 which is 46
float temperatureCelsius = tempSensor.read();
float temperatureFahrenheit = (temperatureCelsius * 9 / 5) + 32;
cout << "Temperature: " << temperatureCelsius << " C / " << temperatureFahrenheit << " F" <<
endl;
// Task 4: Read the push button on P8.16
GPIO pushButton(46, GPIO::INPUT);
bool buttonState = pushButton.getValue();
// Task 5: If the push button in item 4 was pushed, turn on the LED on P9.12
if (buttonState) {
LED ledP912(60);
ledP912.turnOn();
}
return 0;
}
