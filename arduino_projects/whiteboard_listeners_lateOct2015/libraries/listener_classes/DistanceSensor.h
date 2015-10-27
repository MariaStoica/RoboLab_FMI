#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <Observer.h>
#include <string>
#include <iostream>

using namespace std;

class DistanceSensor : public Observer
{
public:
	DistanceSensor(int analog_pin_id, string desc);
	virtual ~DistanceSensor();

	void WhoAreYou() const;
	virtual void Notify(Observee* observee);
private:
	int analog_pin_id;
	string desc;

	// Disabling default copy constructor 
	// and default assignment operator.
	DistanceSensor(const DistanceSensor& yRef);									
	DistanceSensor& operator=(const DistanceSensor& yRef);
};
