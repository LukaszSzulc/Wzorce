#pragma once
class Singleton
{
private:
	static Singleton* instancja;

protected:
	Singleton() {};

public:
	static Singleton* PobierzInstancję();
};

Singleton* Singleton::instancja = 0;