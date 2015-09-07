#pragma once
class Singleton
{
private:
	static Singleton* instancja;

protected:
	Singleton() {}; //ukryty konstruktor

public:
	static Singleton* PobierzInstancję()
	{
		if (instancja == 0)
			instancja = new Singleton();
		return instancja;
	}
};

Singleton* Singleton::instancja = 0;