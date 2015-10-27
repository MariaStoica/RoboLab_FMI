#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <vector>
#include <algorithm>
#include <Observer.h>

using namespace std;

class Observee
{
public:
	
	virtual ~Observee();

	bool AddObserver(Observer* observer);
	bool RemoveObserver(Observer* observer);
	bool NotifyObservers();

protected:
	Observee();
private: 
	vector<Observer*> m_ObserverVec; // the observee keeps its observers

	// Disabling default copy constructor 
	// and default assignment operator.
	Observee(const Observee& yRef);									
	Observee& operator=(const Observee& yRef);	
};
