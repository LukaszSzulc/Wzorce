#include "BudowniczyLabiryntu.h"
#include <stdexcept>


void BudowniczyLabiryntu::RozpocznijBudowe(int liczbaKomórek)
{
	this->liczbaKomorek = liczbaKomórek;	
	komorki = new PKomorka[liczbaKomórek];
	for(int i =0; i<liczbaKomórek; i++) komorki[i]=new Komorka(i);
	czyLabiryntZbudowany = false;	
}

void BudowniczyLabiryntu::ZakonczBudowe(int indeksPoczatkowejkomorki, int indeksCelu)
{
	budowanyLabirynt = new Labirynt(liczbaKomorek, indeksPoczatkowejkomorki, indeksCelu);
	for(int i = 0; i< liczbaKomorek; ++i)
		budowanyLabirynt->DodajKomórkę(i, komorki[i]);
	delete [] komorki;
	komorki = NULL;
	czyLabiryntZbudowany = true;
}

Kierunek BudowniczyLabiryntu::PrzeciwnyKierunek(Kierunek kierunek)
{
	switch(kierunek)
	{
	case Polnoc: return Poludnie;
	case Poludnie: return Polnoc;
	case Wschod: return Zachod;
	case Zachod: return Wschod;
	default:
		throw std::runtime_error("Nierozpoznany kierunek");
	}
}

void BudowniczyLabiryntu::Sprawdz(int indeks1, int indeks2)
{
	if(komorki==NULL) throw std::runtime_error("Wpierw nalezy uruchomic metode 'RozpocznijBudowe'");
	if(indeks1<0 || indeks1>=liczbaKomorek) throw std::invalid_argument("Nieprawidlowa wartosc argumentu 'indeks1'");
	if(indeks2<0 || indeks2>= liczbaKomorek) throw std::invalid_argument("Nieprawidlowa wartosc argumentu 'indeks2'");
}

Labirynt* BudowniczyLabiryntu::PobierzLabirynt()
{
	if(czyLabiryntZbudowany) return budowanyLabirynt;
	else throw std::runtime_error("Labirynt nie jest eszcze gotowy");
}

//---------------------------------------

void StandardowyBudowniczyLabiryntu::WiazKomorki(int indeks1, int indeks2, Kierunek kierunekOd1Do2)
{
	Sprawdz(indeks1, indeks2);
	komorki[indeks1]->PowiaZMiejscem(kierunekOd1Do2, komorki[indeks2]);
	komorki[indeks2]->PowiaZMiejscem(PrzeciwnyKierunek(kierunekOd1Do2), komorki[indeks1]);
}

void StandardowyBudowniczyLabiryntu::WstawDrzwiMiedzyKomrki(int indeks1, int indeks2, ::Kierunek kierunekOd1Do2)
{
	Sprawdz(indeks1, indeks2);
	Drzwi* drzwi = new Drzwi(indeks1, indeks2);
	komorki[indeks1]->PowiaZMiejscem(kierunekOd1Do2, drzwi);
	komorki[indeks2]->PowiaZMiejscem(PrzeciwnyKierunek(kierunekOd1Do2), drzwi);
}
//---------------------------------------

Labirynt* TworzLabirynt(BudowniczyLabiryntu& budowniczy)
{
	budowniczy.RozpocznijBudowe(15);

	budowniczy.WiazKomorki(0, 1, Wschod);
	budowniczy.WiazKomorki(1, 2, Wschod);
	budowniczy.WiazKomorki(2, 3, Poludnie);
	budowniczy.WiazKomorki(3, 4, Wschod);
	budowniczy.WiazKomorki(4, 5, Wschod);
	budowniczy.WiazKomorki(3, 6, Poludnie);

	budowniczy.WstawDrzwiMiedzykomorki(6, 10, Poludnie);

	budowniczy.WiazKomorki(10, 9, Zachod);
	budowniczy.WiazKomorki(9, 11, Poludnie);
	budowniczy.WiazKomorki(11, 12, Wschod);
	budowniczy.WiazKomorki(12, 13, Wschod);
	budowniczy.WiazKomorki(13, 14, Wschod);

	budowniczy.ZakonczBudowe(0, 14);
	return budowniczy.PobierzLabirynt();
}