#include <ColorSensor.h>
#include <iostream>

using namespace std;

ColorSensor::ColorSensor(int analog_pin_id, string desc): analog_pin_id(analog_pin_id), desc(desc)
{
	// nothing to create
}

ColorSensor::~ColorSensor()
{
	// nothing to destroy
}

void ColorSensor::Notify(Observee* observee)
{
	// we're on white! abandon ship!
	cout << "We're on white!";
}

void ColorSensor::WhoAreYou() const
{
       cout << "I am ";
	cout << desc;
	cout << "\n";
}
