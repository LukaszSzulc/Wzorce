#include "Singleton.h"


Singleton* Singleton::PobierzInstancję()
{
	if(instancja==0)
		instancja=new Singleton();
	return instancja;
}