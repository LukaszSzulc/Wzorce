#include "Kontroler.h"
#ifdef _WIN32
#include <conio.h> //_getch
#else
#include "linuxConio.h"
#endif

void Kontroler::SprobujPrzejsc(Kierunek kierunek)
{
	Widok::WyswietlInformacjeOProbiePrzejsciaWKierunku(kierunek);
	RezultatProbyWejscia wynik = model->PrzejdzWKierunku(kierunek);
	widok->WyswietlInformacjeORezultacieProbyPrzejscia(wynik);
}

void Kontroler::SpróbujOtworzycDrzwi()
{
	widok->WyswietlInformacjeOProbieOtwarciaDrzwi();
	bool wynik = model->PobierzBiezacaKomorke()->OtworzDrzwi();
	widok->WyswietlInformacjeORezultacieProbyOtwarciaDrzwi(wynik);
}

void Kontroler::Uruchom()
{
	bool Zakoncz = false;
	do
	{
		widok->WyswietlInformacjeOBiezacejKomorce();
		int kodKlawisza = _getch();
		//std::cout << "Kod nacisnietego klawisza: " << kodKlawisza << "\n";

		switch(kodKlawisza)
		{
		case 97:
		case 75:
			//przesuń na zachód
			SprobujPrzejsc(Zachod);			
			break;
		case 100:
		case 77:
			//przesuń na wschód
			SprobujPrzejsc(Wschod);
			break;
		case 119:
		case 72:
			//przesuń na Poludnie
			SprobujPrzejsc(Poludnie);
			break;
		case 115:
		case 80:
			//przesuń na południe
			SprobujPrzejsc(Poludnie);
			break;
		case 101:
			SpróbujOtworzycDrzwi();
			break;
		case 27:
			model->Zakoncz();
			break;
		}

		widok->WyswietlInformacjeOStanieGry();
		if(model->PobierzStanGry()!=Niezakonczona) Zakoncz = true;
	}
	while(!Zakoncz);
}

/*
//metody wytwórcze
Komorka* Kontroler::TworzKomorke(int indeks)
{
	return new Komorka(indeks);
}

Drzwi* Kontroler::TworzDrzwi(int indekskomorki1, int indekskomorki2)
{
	return new Drzwi(indekskomorki1, indekskomorki2);
}

Labirynt* Kontroler::TworzLabirynt()
{
	const int liczbaKomorek = 15;
	Labirynt* labirynt = new Labirynt(liczbaKomorek, 0, 14);
	PKomorka* komorki = new PKomorka[liczbaKomorek];
	for(int i =0; i<liczbaKomorek; i++)
		komorki[i] = TworzKomorke(i);

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

	Drzwi* drzwi_6_10 = TworzDrzwi(6, 10);
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
*/
