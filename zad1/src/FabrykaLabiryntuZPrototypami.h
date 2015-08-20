#pragma once
#include "Model.h"

class FabrykaLabiryntuZPrototypami
{
private:
	Komórka* prototypKomórki;
	Ściana* prototypŚciany;
	Drzwi* prototypDrzwi;

public:
	FabrykaLabiryntuZPrototypami(Komórka* prototypKomórki, Ściana* prototypŚciany, Drzwi* prototypDrzwi)
		:prototypKomórki(prototypKomórki), prototypŚciany(prototypŚciany), prototypDrzwi(prototypDrzwi)
	{
	}

	Komórka* TwórzKomórkę(int indeks) const;
	Ściana* TwórzŚcianę() const;
	Drzwi* TwórzDrzwi(int indeksKomórki1, int indeksKomórki2) const;
	virtual Labirynt* TwórzLabirynt() const = 0;
};

//--------------------------------------

class StandardowaFabrykaLabiryntuZPrototypami : FabrykaLabiryntuZPrototypami
{
public:
	StandardowaFabrykaLabiryntuZPrototypami(Komórka* prototypKomórki, Ściana* prototypŚciany, Drzwi* prototypDrzwi)
		:FabrykaLabiryntuZPrototypami(prototypKomórki, prototypŚciany, prototypDrzwi)
	{
	}

	virtual Labirynt* TwórzLabirynt() const;
};