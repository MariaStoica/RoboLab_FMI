#include "stdafx.h"
#include <DistanceSensor.h>

using namespace std;

DistanceSensor::DistanceSensor(int analog_pin_id, string desc): analog_pin_id(analog_pin_id), desc(desc)
{
	// nothing to create
}

DistanceSensor::~DistanceSensor()
{
	// nothing to destroy
}

void DistanceSensor::Notify(Observee* observee)
{
	// Enemy detected!
	// cout << "Enemy detected!";
}

void DistanceSensor::WhoAreYou() const
{
	// cout << "I am ";
	// cout << desc;
	// cout << "\n";
}
