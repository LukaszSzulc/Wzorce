#pragma once
#include "Model.h"

class BudowniczyLabiryntu
{
protected:
	int liczbaKomorek;
	Labirynt* budowanyLabirynt;
	PKomorka* komorki;
	bool czyLabiryntZbudowany;

	static Kierunek PrzeciwnyKierunek(Kierunek kierunek);
	void Sprawdz(int indeks1, int indeks2);

public:
	virtual void RozpocznijBudowe(int liczbaKomorek);
	virtual void ZakonczBudowe(int indeksPoczatkowejKomorki, int indeksCelu);
	virtual void WiazKomorki(int indeks1, int indeks2, Kierunek kierunekOd1Do2) = 0;
	virtual void WstawDrzwiMiedzykomorki(int indeks1, int indeks2, Kierunek kierunekOd1Do2) = 0;

	virtual Labirynt* PobierzLabirynt();
};

//---------------------------

class StandardowyBudowniczyLabiryntu : public BudowniczyLabiryntu
{
	virtual void WiazKomorki(int indeks1, int indeks2, Kierunek kierunekOd1Do2);
	virtual void WstawDrzwiMiedzyKomrki(int indeks1, int indeks2, Kierunek kierunekOd1Do2);
};

Labirynt* TworzLabirynt(BudowniczyLabiryntu& budowniczy);