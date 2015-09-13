#pragma once
#include "Model.h"

class BudowniczyLabiryntuSingleton
{
private:
	static BudowniczyLabiryntuSingleton* instancja;

protected:
	int liczbaKomorek;
	Labirynt* budowanyLabirynt;
	PKomorka* komorki;
	bool czyLabiryntZbudowany;

	static Kierunek PrzeciwnyKierunek(Kierunek kierunek);
	void Sprawdz(int indeks1, int indeks2);

	BudowniczyLabiryntuSingleton() {};

public:
	static BudowniczyLabiryntuSingleton* PobierzStandardowegoBudowniczegoLabiryntu();

	virtual void RozpocznijBudowe(int liczbaKomorek);
	virtual void ZakonczBudowę(int indeksPoczatkowejkomorki, int indeksCelu);
	virtual void Wiazkomorki(int indeks1, int indeks2, Kierunek kierunekOd1Do2) = 0;
	virtual void WstawDrzwiMiedzykomorki(int indeks1, int indeks2, Kierunek kierunekOd1Do2) = 0;

	virtual Labirynt* PobierzLabirynt();
};

//---------------------------

class StandardowyBudowniczyLabiryntuSingleton : public BudowniczyLabiryntuSingleton
{
public:
	virtual void Wiazkomorki(int indeks1, int indeks2, Kierunek kierunekOd1Do2);
	virtual void WstawDrzwiMiedzykomorki(int indeks1, int indeks2, Kierunek kierunekOd1Do2);
};

Labirynt* TworzLabirynt(BudowniczyLabiryntuSingleton& budowniczy);