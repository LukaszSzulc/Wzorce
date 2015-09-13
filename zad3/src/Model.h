#pragma once

#include <stddef.h>

enum RezultatProbyWejscia { Nieokrslony = 0, Powodzenie, NieMoznaWejsc, Zamkniete };

//--------------------------------------

class MiejsceWLabiryncie
{
public:
	virtual RezultatProbyWejscia SprobujWejsc() = 0;
	virtual int Wejdz(int indeksBiezacejKomorki) { return -1; }
	virtual bool Otworz() { return false; }
	virtual MiejsceWLabiryncie* Klonuj() = 0;
};

//--------------------------------------

enum Kierunek { Polnoc = 0, Poludnie = 1, Wschod = 2, Zachod = 3 };

//--------------------------------------

class Komorka : public MiejsceWLabiryncie
{
private:
	int indeks;
	MiejsceWLabiryncie* sasiednieMiejsca[4];

public:
	Komorka(int indeks);
	void Inicjuj(int indeks);

	MiejsceWLabiryncie* PobierzMiejscePoStronie(Kierunek kierunek) const
	{
		return sasiednieMiejsca[kierunek];
	}

	void PowiaZMiejscem(Kierunek kierunek, MiejsceWLabiryncie* miejsce)
	{
		sasiednieMiejsca[kierunek] = miejsce;
	}

	virtual RezultatProbyWejscia SprobujWejsc()
	{
		return Powodzenie;
	}

	virtual int Wejdz(int indeksBiezaccejkomorki)
	{
		return indeks;
	}

	int PobierzIndeks()
	{
		return indeks;
	}

	bool OtworzDrzwi(Kierunek kierunek);
	bool OtworzDrzwi();

	virtual Komorka* Klonuj()
	{
		return new Komorka(*this);
	}
};

typedef Komorka* PKomorka;

//--------------------------------------

class Sciana : public MiejsceWLabiryncie
{
public:
	virtual RezultatProbyWejscia SprobujWejsc()
	{
		return NieMoznaWejsc;
	}

	virtual Sciana* Klonuj()
	{
		return new Sciana(*this);
	}
};

//--------------------------------------

class Drzwi : public MiejsceWLabiryncie
{
private:
	int indekskomorki1, indekskomorki2;
	bool czyOtwarte;

public:
	Drzwi(int indekskomorki1, int indekskomorki2)		
	{
		Inicjuj(indekskomorki1, indekskomorki2);
	}

	void Inicjuj(int indekskomorki1, int indekskomorki2)
	{
		this->indekskomorki1 = indekskomorki1;
		this->indekskomorki2 = indekskomorki2;
		czyOtwarte = false;
	}

	virtual RezultatProbyWejscia SprobujWejsc()
	{
		return czyOtwarte ? Powodzenie : Zamkniete;
	}

	virtual int Wejdz(int indeksBiezacejkomorki)
	{
		if(czyOtwarte) return (indeksBiezacejkomorki == indekskomorki1)? indekskomorki2:indekskomorki1;
		else return indeksBiezacejkomorki;
	}

	virtual bool Otworz()
	{
		czyOtwarte = true;
		return czyOtwarte;
	}

	virtual Drzwi* Klonuj()
	{
		return new Drzwi(*this);
	}
};

//--------------------------------------

enum StanGry { Niezakonczona = 0, Umierasz, Wygrana };

//--------------------------------------

class Labirynt
{
private:
	int liczbaKomorek;
	PKomorka* komorki;
	int indeksBiezacejkomorki, indeksCelu;
	StanGry stanGry;

	Komorka* pobierzKomorke(int indeks)
	{
		if(indeks>=0 && indeks< liczbaKomorek) return komorki[indeks];
		else return NULL;
	}

public:
	Labirynt(int liczbaKomórek, int indeksPoczatkowejkomorki, int indeksCelu);
	~Labirynt();

	void DodajKomórkę(int indeks, Komorka* Komorka);

	Komorka* PobierzBiezacaKomorke()
	{
		return pobierzKomorke(indeksBiezacejkomorki);
	}

	RezultatProbyWejscia PrzejdzWKierunku(Kierunek kierunek);

	void Zakoncz()
	{
		stanGry = Umierasz;
	}

	StanGry PobierzStanGry()
	{
		if(indeksBiezacejkomorki == indeksCelu) stanGry = Wygrana;
		return stanGry;
	}
};

//--------------------------------------

Labirynt* TworzLabirynt();