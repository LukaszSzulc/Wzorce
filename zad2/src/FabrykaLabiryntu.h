#pragma once
#include "Model.h"

class FabrykaLabiryntu
{
public:
	virtual Komórka* TwórzKomórkę(int indeks) const;
	virtual Drzwi* TwórzDrzwi(int indeksKomórki1, int indeksKomórki2) const;
	virtual Labirynt* TwórzLabirynt() const = 0;
};

//---------------------

class StandardowaFabrykaLabiryntu : public FabrykaLabiryntu
{
public:
	virtual Labirynt* TwórzLabirynt() const;
};
