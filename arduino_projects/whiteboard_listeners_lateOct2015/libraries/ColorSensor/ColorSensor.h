#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <Observer.h>
#include <string> // it is needed

using namespace std;

class ColorSensor : public Observer
{
public:
	ColorSensor(int analog_pin_id, string desc);
	virtual ~ColorSensor();

	void WhoAreYou() const;
	virtual void Notify(Observee* observee);
private:
	int analog_pin_id;
	string desc;

	// Disabling default copy constructor 
	// and default assignment operator.
	ColorSensor(const ColorSensor& yRef);									
	ColorSensor& operator=(const ColorSensor& yRef);
};
