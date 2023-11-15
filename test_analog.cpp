//Main code that exercises the class. One can use the
//temperature sensor to read analog values. This test application simply instantiates an AnalogIn
//object with number zero, then calls getNumber(), and finally calls readAdcSample()
//
#include "AnalogIn.h"
#include <iostream>

using namespace std;

float getTemperature(int adc_value);

int main(){
	cout << "Testing ..." << endl;
	AnalogIn analogInput(0);
	cout << "Analog Input: " << analogInput.getNumber() << endl;
		int ADC_val = analogInput.readAdcSample();
	cout << "Reading ADC Value ..." << endl;
	cout << "Analog Value Read: " << ADC_val << endl;
	
	cout << "Reading Temperature ..." << endl;
	float temp = getTemperature(ADC_val);
	float temp_F = 32+((temp*9)/5);
	cout << "Temperature Read: " << temp << "°C"<< temp << "°C (" << temp_F << "°F)" << endl;
	return 0;
}

