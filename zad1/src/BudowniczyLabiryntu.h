#pragma once

#include "Model.h"

class BudowniczyLabiryntu
{
protected:
	int liczbaKomórek;
	Labirynt* budowanyLabirynt;
	PKomórka* komórki;
	bool czyLabiryntZbudowany = false;

	static Kierunek PrzeciwnyKierunek(Kierunek kierunek);
	void Sprawdź(int indeks1, int indeks2);

public:
	virtual void RozpocznijBudowę(int liczbaKomórek, int indeksPoczątkowejKomórki, int indeksCelu);
	virtual void ZakończBudowę();
	virtual void WiążKomórki(int indeks1, int indeks2, Kierunek kierunekOd1Do2) = 0;
	virtual void WstawDrzwiMiędzyKomórki(int indeks1, int indeks2, Kierunek kierunekOd1Do2) = 0;

	virtual Labirynt* PobierzLabirynt();
};

//----------------------------

class StandardowyBudowniczyLabiryntu : public BudowniczyLabiryntu
{
	virtual void WiążKomórki(int indeks1, int indeks2, Kierunek kierunekOd1Do2);
	virtual void WstawDrzwiMiędzyKomórki(int indeks1, int indeks2, Kierunek kierunekOd1Do2);
};

//----------------------------

Labirynt* TwórzLabirynt(BudowniczyLabiryntu& budowniczy);
