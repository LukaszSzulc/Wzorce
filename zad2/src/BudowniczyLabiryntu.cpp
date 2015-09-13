#include "BudowniczyLabiryntu.h"
#include <stdexcept>

void BudowniczyLabiryntu::RozpocznijBudowę(int liczbaKomórek, int indeksPoczątku, int indeksCelu)
{
	this->liczbaKomórek = liczbaKomórek;
	budowanyLabirynt = new Labirynt(liczbaKomórek, indeksPoczątku, indeksCelu);
	komórki = new PKomórka[liczbaKomórek];
	for (int i = 0; i < liczbaKomórek; i++) komórki[i] = new Komórka(i);
	czyLabiryntZbudowany = false;
}

void BudowniczyLabiryntu::ZakończBudowę()
{
	for (int i = 0; i < liczbaKomórek; ++i) budowanyLabirynt->DodajKomórkę(i, komórki[i]);
	delete[] komórki;
	komórki = NULL;
	czyLabiryntZbudowany = true;
}

/*static*/ Kierunek BudowniczyLabiryntu::PrzeciwnyKierunek(Kierunek kierunek)
{
	switch (kierunek)
	{
	case Północ: return Południe;
	case Południe: return Północ;
	case Wschód: return Zachód;
	case Zachód: return Wschód;
	default:
		throw std::runtime_error("Nierozpoznany kierunek");
	}
}

void BudowniczyLabiryntu::Sprawdź(int indeks1, int indeks2)
{
	if (komórki == NULL) throw std::runtime_error("Wpierw nalezy uruchomic metode 'RozpocznijBudowe'");
	if (indeks1<0 || indeks1 >= liczbaKomórek) throw std::invalid_argument("Nieprawidlowa wartosc argumentu 'indeks1'");
	if (indeks2<0 || indeks2 >= liczbaKomórek) throw std::invalid_argument("Nieprawidlowa wartosc argumentu 'indeks2'");
	if (czyLabiryntZbudowany) throw std::runtime_error("Budowa labiryntu zostala juz zakonczona");
}

Labirynt* BudowniczyLabiryntu::PobierzLabirynt()
{
	if (czyLabiryntZbudowany) return budowanyLabirynt;
	else throw std::runtime_error("Labirynt nie jest jeszcze gotowy");
}

//----------------------------

//założenie upraszczające, którego nie ma w oryginalnych klasach
void StandardowyBudowniczyLabiryntu::WiążKomórki(int indeks1, int indeks2, Kierunek kierunek)
{	//kierunek od indeks1 do indeks2
	Sprawdź(indeks1, indeks2);
	komórki[indeks1]->PowiążZMiejscem(kierunek, komórki[indeks2]);
	komórki[indeks2]->PowiążZMiejscem(PrzeciwnyKierunek(kierunek), komórki[indeks1]);
}

void StandardowyBudowniczyLabiryntu::WstawDrzwiMiędzyKomórki(int indeks1, int indeks2, Kierunek kierunek)
{ //kierunek od indeks1 do indeks2
	Sprawdź(indeks1, indeks2);
	Drzwi* drzwi = new Drzwi(indeks1, indeks2);
	komórki[indeks1]->PowiążZMiejscem(kierunek, drzwi);
	komórki[indeks2]->PowiążZMiejscem(PrzeciwnyKierunek(kierunek), drzwi);
}

//----------------------------

Labirynt* TwórzLabirynt(BudowniczyLabiryntu& budowniczy)
{
	budowniczy.RozpocznijBudowę(15, 0, 14);

	budowniczy.WiążKomórki(0, 1, Wschód);
	budowniczy.WiążKomórki(1, 2, Wschód);	
	budowniczy.WiążKomórki(2, 3, Południe);	
	budowniczy.WiążKomórki(3, 4, Wschód);
	budowniczy.WiążKomórki(4, 5, Wschód);
	budowniczy.WiążKomórki(3, 6, Południe);
	budowniczy.WiążKomórki(4, 7, Południe);
	budowniczy.WiążKomórki(5, 8, Południe);
	budowniczy.WiążKomórki(6, 7, Wschód);
	budowniczy.WiążKomórki(7, 8, Wschód);

	budowniczy.WstawDrzwiMiędzyKomórki(6, 10, Południe);

	budowniczy.WiążKomórki(10, 9, Zachód);
	budowniczy.WiążKomórki(9, 11, Południe);
	budowniczy.WiążKomórki(11, 12, Wschód);
	budowniczy.WiążKomórki(12, 13, Wschód);
	budowniczy.WiążKomórki(13, 14, Wschód);

	budowniczy.ZakończBudowę();
	return budowniczy.PobierzLabirynt();
}
