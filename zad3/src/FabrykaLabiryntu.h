#pragma once

#include "Model.h"

class FabrykaLabiryntu //fabryka abstrakcyjna
{
public:
	virtual Komorka* TworzKomorke(int indeks) const;
	virtual Drzwi* TworzDrzwi(int indekskomorki1, int indekskomorki2) const;
	virtual Labirynt* TworzLabirynt() const = 0;
};

//-------------------------------

class StandardowaFabrykaLabiryntu : public FabrykaLabiryntu //fabryka konkretna
{
public:
	virtual Labirynt* TworzLabirynt() const;
};