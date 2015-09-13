#include "Model.h"

Komorka::Komorka(int indeks)
{
	Inicjuj(indeks);	
}

void Komorka::Inicjuj(int indeks)
{	
	this->indeks = indeks;
	for(int i=0; i<4; i++) sasiednieMiejsca[i] = new Sciana();
}

bool Komorka::OtworzDrzwi(::Kierunek kierunek)
{
	return sasiednieMiejsca[kierunek]->Otworz();

}

bool Komorka::OtworzDrzwi()
{
	bool wynik = false;
	for (int i = 0; i<4; i++)
		if (OtworzDrzwi((Kierunek)i))
			wynik = true;
	return wynik;

}
//--------------------------------------

Labirynt::Labirynt(int liczbaKomorek, int indeksPoczatkowejkomorki, int indeksCelu)
	:liczbaKomorek(liczbaKomorek), indeksBiezacejkomorki(indeksPoczatkowejkomorki), indeksCelu(indeksCelu),
	stanGry(Niezakonczona)
{
	komorki = new PKomorka[liczbaKomorek];
}

Labirynt::~Labirynt(void)
{
	for(int i=0;i<liczbaKomorek;++i) delete komorki[i];
	delete [] komorki;
}

void Labirynt::DodajKomórkę(int indeks, Komorka* Komorka)
{
	komorki[indeks] = Komorka;
}

RezultatProbyWejscia Labirynt::PrzejdzWKierunku(Kierunek kierunek)
{
	MiejsceWLabiryncie* miejsce = PobierzBiezacaKomorke()->PobierzMiejscePoStronie(kierunek);
	RezultatProbyWejscia wynik = miejsce->SprobujWejsc();
	if(wynik == Powodzenie) indeksBiezacejkomorki = miejsce->Wejdz(indeksBiezacejkomorki);
	return wynik;
}

//--------------------------------------

Labirynt* TworzLabirynt()
{
	const int liczbaKomorek = 15;
	Labirynt* labirynt = new Labirynt(liczbaKomorek, 0, 14);
	PKomorka* komorki = new PKomorka[liczbaKomorek];
	for(int i =0; i<liczbaKomorek; i++)
		komorki[i] = new Komorka(i);

	komorki[0]->PowiaZMiejscem(Wschod, komorki[1]);
	komorki[1]->PowiaZMiejscem(Zachod, komorki[0]);

	komorki[1]->PowiaZMiejscem(Wschod, komorki[2]);
	komorki[2]->PowiaZMiejscem(Zachod, komorki[1]);

	komorki[2]->PowiaZMiejscem(Poludnie, komorki[3]);
	komorki[3]->PowiaZMiejscem(Poludnie, komorki[2]);

	komorki[3]->PowiaZMiejscem(Wschod, komorki[4]);
	komorki[4]->PowiaZMiejscem(Zachod, komorki[3]);

	komorki[4]->PowiaZMiejscem(Wschod, komorki[5]);
	komorki[5]->PowiaZMiejscem(Zachod, komorki[4]);

	komorki[3]->PowiaZMiejscem(Poludnie, komorki[6]);
	komorki[6]->PowiaZMiejscem(Poludnie, komorki[3]);

	Drzwi* drzwi_6_10 = new Drzwi(6, 10);
	komorki[6]->PowiaZMiejscem(Poludnie, drzwi_6_10);
	komorki[10]->PowiaZMiejscem(Poludnie, drzwi_6_10);

	komorki[10]->PowiaZMiejscem(Zachod, komorki[9]);
	komorki[9]->PowiaZMiejscem(Wschod, komorki[10]);

	komorki[9]->PowiaZMiejscem(Poludnie, komorki[11]);
	komorki[11]->PowiaZMiejscem(Poludnie, komorki[9]);

	komorki[11]->PowiaZMiejscem(Wschod, komorki[12]);
	komorki[12]->PowiaZMiejscem(Zachod, komorki[11]);

	komorki[12]->PowiaZMiejscem(Wschod, komorki[13]);
	komorki[13]->PowiaZMiejscem(Zachod, komorki[12]);

	komorki[13]->PowiaZMiejscem(Wschod, komorki[14]);
	komorki[14]->PowiaZMiejscem(Zachod, komorki[13]);

	for(int i =0; i<liczbaKomorek; ++i)
		labirynt->DodajKomórkę(i, komorki[i]);
	delete [] komorki;

	return labirynt;
}