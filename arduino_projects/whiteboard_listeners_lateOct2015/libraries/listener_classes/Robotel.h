#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <Observee.h>

using namespace std;

class Robotel : public Observee
{
public:
	Robotel();
	virtual ~Robotel();
private:
	Robotel(const Robotel& yRef);
	Robotel& operator=(const Robotel& yRef);
};
