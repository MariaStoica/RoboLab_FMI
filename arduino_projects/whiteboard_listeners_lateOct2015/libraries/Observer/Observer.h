//---------------------------
// Stijn Lammens
// October 2010
// http://www.stijnlammens.com
//---------------------------
#pragma once

#include "stdafx.h"
#include <vector>
using namespace std;

class Observee;
//-----------------------------------------------------
// Observer Class									
//-----------------------------------------------------
class Observer
{
public:
	virtual ~Observer();		// Destructor
	virtual void Notify(Observee* observee){} // nu pune ; aici ca eroare
protected:
	Observer();	 // Constructor is protected!
private: 

	// -------------------------
	// Disabling default copy constructor and default 
	// assignment operator.
	// -------------------------
	Observer(const Observer& yRef);									
	Observer& operator=(const Observer& yRef);	
};

 
