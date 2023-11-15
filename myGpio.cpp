#include "myGpio.h"
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

int main() {
//	MYGPIO GPIO(9); //Instantiate an object GPIO to pin 9.12
//	GPIO.setDirection(OUTPUT); //Set GPIO pin 9.12 as an Output
//	GPIO.setValue(HIGH); //set value of pin 9.12 as HIGH
	class MYGPIO::MYGPIO(int number):number(number){ //constructer class MYGPIO that takes integer parameter and initialize member variable number with parameter value number
		name = "gpio" + to_string(number);
		path = "/sys/class/gpio/" + name + "/";
		stream.open((path + "value").c_str());
		
	}

int MYGPIO::getNumber(){ //create member function getNumber in the MYGPIO class

	return number; //return value in number variable
}

void MYGPIO::setDirection(GPIO_Direction dir){ //create member function setDirection that takes string parameter dir
	string direction = read(path, "direction");
	if (dir == OUTPUT){
		direction = "out";
	}else{
		direction = "in";
	}
	write(path,"direction",direction);
//example invocation setDirectio


}

GPIO_DIRECTION MYGPIO::getDirection(GPIO_Direction dir){
	string direction = read(path, "direction");
	re	

