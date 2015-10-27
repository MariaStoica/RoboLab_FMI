#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <vector>
#include <Observee.h>

using namespace std;

class Observer
{
public:
	virtual ~Observer();
	virtual void Notify(Observee* observee);
protected:
	Observer();
private:
	// Disabling default copy constructor 
	// and default assignment operator.
	Observer(const Observer& yRef);									
	Observer& operator=(const Observer& yRef);
};
