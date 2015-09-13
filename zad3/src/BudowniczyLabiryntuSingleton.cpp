#include "BudowniczyLabiryntuSingleton.h"
#include <stdexcept>


void BudowniczyLabiryntuSingleton::RozpocznijBudowe(int liczbaKomorek)
{
	this->liczbaKomorek = liczbaKomorek;	
	komorki = new PKomorka[liczbaKomorek];
	for(int i =0; i<liczbaKomorek; i++) komorki[i]=new Komorka(i);
	czyLabiryntZbudowany = false;	
}

void BudowniczyLabiryntuSingleton::ZakonczBudowę(int indeksPoczatkowejkomorki, int indeksCelu)
{
	budowanyLabirynt = new Labirynt(liczbaKomorek, indeksPoczatkowejkomorki, indeksCelu);
	for(int i = 0; i< liczbaKomorek; ++i)
		budowanyLabirynt->DodajKomórkę(i, komorki[i]);
	delete [] komorki;
	komorki = NULL;
	czyLabiryntZbudowany = true;
}

Kierunek BudowniczyLabiryntuSingleton::PrzeciwnyKierunek(Kierunek kierunek)
{
	switch(kierunek)
	{
	case Polnoc: return Poludnie;
	case Poludnie: return Poludnie;
	case Wschod: return Zachod;
	case Zachod: return Wschod;
	default:
		throw std::runtime_error("Nierozpoznany kierunek");
	}
}

void BudowniczyLabiryntuSingleton::Sprawdz(int indeks1, int indeks2)
{
	if(komorki==NULL) throw std::runtime_error("Wpierw nalezy uruchomic metode 'RozpocznijBudowe'");
	if(indeks1<0 || indeks1>=liczbaKomorek) throw std::invalid_argument("Nieprawidlowa wartosc argumentu 'indeks1'");
	if(indeks2<0 || indeks2>=liczbaKomorek) throw std::invalid_argument("Nieprawidlowa wartosc argumentu 'indeks2'");	
}

Labirynt* BudowniczyLabiryntuSingleton::PobierzLabirynt()
{
	if(czyLabiryntZbudowany) return budowanyLabirynt;
	else throw std::runtime_error("Labirynt nie jest eszcze gotowy");
}

BudowniczyLabiryntuSingleton* BudowniczyLabiryntuSingleton::instancja = 0;

BudowniczyLabiryntuSingleton* BudowniczyLabiryntuSingleton::PobierzStandardowegoBudowniczegoLabiryntu()
{
	if(instancja==0)
		instancja = new StandardowyBudowniczyLabiryntuSingleton();
	return instancja;
}

//---------------------------------------

void StandardowyBudowniczyLabiryntuSingleton::Wiazkomorki(int indeks1, int indeks2, ::Kierunek kierunekOd1Do2)
{
	Sprawdz(indeks1, indeks2);
	komorki[indeks1]->PowiaZMiejscem(kierunekOd1Do2, komorki[indeks2]);
	komorki[indeks2]->PowiaZMiejscem(PrzeciwnyKierunek(kierunekOd1Do2), komorki[indeks1]);

}

void StandardowyBudowniczyLabiryntuSingleton::WstawDrzwiMiedzykomorki(int indeks1, int indeks2, Kierunek kierunekOd1Do2)
{
	Sprawdz(indeks1, indeks2);
	Drzwi* drzwi = new Drzwi(indeks1, indeks2);
	komorki[indeks1]->PowiaZMiejscem(kierunekOd1Do2, drzwi);
	komorki[indeks2]->PowiaZMiejscem(PrzeciwnyKierunek(kierunekOd1Do2), drzwi);
}

//---------------------------------------

Labirynt* TworzLabirynt(BudowniczyLabiryntuSingleton& budowniczy)
{
	budowniczy.RozpocznijBudowe(15);

	budowniczy.Wiazkomorki(0, 1, Wschod);
	budowniczy.Wiazkomorki(1, 2, Wschod);
	budowniczy.Wiazkomorki(2, 3, Poludnie);
	budowniczy.Wiazkomorki(3, 4, Wschod);
	budowniczy.Wiazkomorki(4, 5, Wschod);
	budowniczy.Wiazkomorki(3, 6, Poludnie);

	budowniczy.WstawDrzwiMiedzykomorki(6, 10, Poludnie);

	budowniczy.Wiazkomorki(10, 9, Zachod);
	budowniczy.Wiazkomorki(9, 11, Poludnie);
	budowniczy.Wiazkomorki(11, 12, Wschod);
	budowniczy.Wiazkomorki(12, 13, Wschod);
	budowniczy.Wiazkomorki(13, 14, Wschod);

	budowniczy.ZakonczBudowę(0, 14);
	return budowniczy.PobierzLabirynt();
}