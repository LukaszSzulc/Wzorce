#pragma once
#include "Model.h"

class FabrykaLabiryntuZPrototypami
{
private:	
	Komorka* prototypkomorki;
	Sciana* prototypSciany; 
	Drzwi* prototypDrzwi;

public:
	FabrykaLabiryntuZPrototypami(Komorka* prototypkomorki, Sciana* prototypSciany, Drzwi* prototypDrzwi)
		:prototypkomorki(prototypkomorki), prototypSciany(prototypSciany), prototypDrzwi(prototypDrzwi)
	{
	}

	Komorka* TworzKomorke(int indeks) const;
	Sciana* TworzSciane() const;
	Drzwi* TworzDrzwi(int indekskomorki1, int indekskomorki2) const;
	virtual Labirynt* TworzLabirynt() const = 0;
};

class StandardowaFabrykaLabiryntuZPrototypami : FabrykaLabiryntuZPrototypami
{
public:
	StandardowaFabrykaLabiryntuZPrototypami(Komorka* prototypkomorki, Sciana* prototypSciany, Drzwi* prototypDrzwi)
		:FabrykaLabiryntuZPrototypami(prototypkomorki, prototypSciany, prototypDrzwi)
	{
	}

	virtual Labirynt* TworzLabirynt() const;
};
