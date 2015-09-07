#pragma once

#include <stddef.h>

enum RezultatPróbyWejścia { Nieokreślony = 0, Powodzenie, NieMożnaWejść, Zamknięte };

//------------------------------------

class MiejsceWLabiryncie
{
public:
	virtual RezultatPróbyWejścia SpróbujWejść() = 0;
	virtual int Wejdź(int indeksBieżącejKomórki) { return -1; }
	virtual bool Otwórz() { return false; }
	virtual MiejsceWLabiryncie* Klonuj() = 0;
};

//------------------------------------

enum Kierunek { Północ = 0, Południe = 1, Wschód = 2, Zachód = 3 };

//------------------------------------

class Komórka : public MiejsceWLabiryncie
{
private:
	int indeks;
	MiejsceWLabiryncie* sąsiednieMiejsca[4];

public:
	Komórka(int indeks);
	void Inicjuj(int indeks);

	MiejsceWLabiryncie* PobierzMiejscePoStronie(Kierunek kierunek) const
	{
		return sąsiednieMiejsca[kierunek];
	}

	void PowiążZMiejscem(Kierunek kierunek, MiejsceWLabiryncie* miejsce)
	{
		sąsiednieMiejsca[kierunek] = miejsce;
	}

	virtual RezultatPróbyWejścia SpróbujWejść()
	{
		return Powodzenie;
	}

	virtual int Wejdź(int indeksBieżącejKomórki)
	{
		return indeks;
	}

	int PobierzIndeks()
	{
		return indeks;
	}

	bool OtwórzDrzwi(Kierunek kierunek);
	bool OtwórzDrzwi();

	virtual Komórka* Klonuj()
	{
		return new Komórka(*this);
	}
};

typedef Komórka* PKomórka;

//------------------------------------

class Ściana : public MiejsceWLabiryncie
{
public:
	virtual RezultatPróbyWejścia SpróbujWejść()
	{
		return NieMożnaWejść;
	};

	virtual Ściana* Klonuj()
	{
		return new Ściana(*this);
	}
};

//------------------------------------

class Drzwi : public MiejsceWLabiryncie
{
private:
	int indeksKomórki1, indeksKomórki2;
	bool czyOtwarte = false;

public:
	void Inicjuj(int indeksKomórki1, int indeksKomórki2)
	{
		this->indeksKomórki1 = indeksKomórki1;
		this->indeksKomórki2 = indeksKomórki2;
	}

	Drzwi(int indeksKomórki1, int indeksKomórki2)
	{
		Inicjuj(indeksKomórki1, indeksKomórki2);
	}

	virtual RezultatPróbyWejścia SpróbujWejść()
	{
		return czyOtwarte ? Powodzenie : Zamknięte;
	};

	virtual int Wejdź(int indeksBieżącejKomórki)
	{
		if (czyOtwarte) return (indeksBieżącejKomórki == indeksKomórki1) ? indeksKomórki2 : indeksKomórki1;
		else return indeksBieżącejKomórki;
	}

	virtual bool Otwórz()
	{
		czyOtwarte = true;
		return czyOtwarte;
	}

	virtual Drzwi* Klonuj()
	{
		return new Drzwi(*this);
	}
};

//------------------------------------

enum StanGry { Niezakończona = 0, Śmierć, Wygrana };

//------------------------------------

class Labirynt
{
private:
	int liczbaKomórek;
	PKomórka* komórki;
	int indeksBieżącejKomórki, indeksCelu;
	StanGry stanGry = Niezakończona;

	Komórka* pobierzKomórkę(int indeks)
	{
		if (indeks >= 0 && indeks < liczbaKomórek) return komórki[indeks];
		else return NULL;
	}

public:
	Labirynt(int liczbaKomórek, int indeksPoczątkowejKomórki, int indeksCelu);
	~Labirynt();
	void DodajKomórkę(int indeks, Komórka* komórka);

	Komórka* PobierzBieżącąKomórkę()
	{
		return pobierzKomórkę(indeksBieżącejKomórki);
	}

	RezultatPróbyWejścia PrzejdźWKierunku(Kierunek kierunek);

	void Zakończ()
	{
		stanGry = Śmierć;
	}

	StanGry PobierzStanGry()
	{
		if (indeksBieżącejKomórki == indeksCelu) stanGry = Wygrana;
		return stanGry;
	}
};

//------------------------------------

Labirynt* TwórzLabirynt();
