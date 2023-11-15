//myGpio2.cpp file that implements MYGPIO class

#include "myGpio.h"

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <iostream>
using namespace std;


MYGPIO::MYGPIO(int number) {
    this->number = number;
    this->name = "gpio" + to_string(number);
    this->path = "/sys/class/gpio/" + this->name + "/";
    stream.open((this->path + "value").c_str());
}

int MYGPIO::getNumber() {
    return number;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir) {
    write(path, "direction", (dir == OUTPUT) ? "out" : "in");
}

GPIO_DIRECTION MYGPIO::getDirection() {
    string direction = read(path, "direction");
    return (direction == "out") ? OUTPUT : INPUT;
}

int MYGPIO::setValue(GPIO_VALUE val) {
    return write(path, "value", (val == HIGH) ? "1" : "0");
}

GPIO_VALUE MYGPIO::getValue() {
    string valueStr = read(path, "value");
    return (valueStr == "1") ? HIGH : LOW;
}

void MYGPIO::toggleOutput() {
    GPIO_VALUE currentValue = getValue();
    setValue((currentValue == HIGH) ? LOW : HIGH);
}

MYGPIO::~MYGPIO() {
    stream.close();
}

int MYGPIO::write(string path, string filename, string value) {
    ofstream fs;
    fs.open((path + filename).c_str());
    if (!fs.is_open()) {
        cerr << "Unable to open file: " << path + filename << endl;
        return -1;
    }
    fs << value;
    fs.close();
    return 0;
}

int MYGPIO::write(string path, string filename, int value) {
    return write(path, filename, to_string(value));
}

string MYGPIO::read(string path, string filename) {
    ifstream fs;
    fs.open((path + filename).c_str());
    if (!fs.is_open()) {
        cerr << "Unable to open file: " << path + filename << endl;
        return "";
    }
    string value;
    getline(fs, value);
    fs.close();
    return value;
}
