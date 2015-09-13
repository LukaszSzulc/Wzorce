#include "Widok.h"
#include <iostream>
using namespace std;

Widok::Widok(Labirynt* model)
	:model(model)
{
}

void Widok::WyswietlInformacjeOKomorce(Komorka* Komorka)
{
	cout << "Jestes w komorce " << Komorka->PobierzIndeks() << ". Wybierz czynnosc (W, S, A, D, E)\n";
}

void Widok::WyswietlInformacjeOBiezacejKomorce() const
{
	WyswietlInformacjeOKomorce(model->PobierzBiezacaKomorke());
}

void Widok::WyswietlInformacjeOProbiePrzejsciaWKierunku(Kierunek kierunek)
{
	cout << "Proba przejscia na ";
	switch(kierunek)
	{
	case Zachod:
		cout << "zachod";
		break;
	case Wschod:
		cout << "wschod";
		break;
	case Polnoc:
		cout << "polnoc";
		break;
	case Poludnie:
		cout << "poludnie";
		break;
	}
	cout << "\n";
}

void Widok::WyswietlInformacjeORezultacieProbyPrzejscia(RezultatProbyWejscia wynik) const
{
	switch(wynik)
	{
	case Powodzenie:
		cout << "Przechodzisz do komorki " << model->PobierzBiezacaKomorke()->PobierzIndeks() << "\n";
		break;
	case Zamkniete:
		cout << "Niestety zamkniete. Musisz wpierw otworzyc\n";
		break;
	case NieMoznaWejsc:
		cout << "Nie umiesz przechodzic przez sciany\n";
		break;
	}
}

void Widok::WyswietlInformacjeOProbieOtwarciaDrzwi() const
{
	cout << "Probujesz otworzyc wszystkie drzwi w komorce " << model->PobierzBiezacaKomorke()->PobierzIndeks() << "\n";
}

void Widok::WyswietlInformacjeORezultacieProbyOtwarciaDrzwi(bool wynik) const
{
	if(wynik) cout << "Otworzyles wszystkie drzwi w komorce " << model->PobierzBiezacaKomorke()->PobierzIndeks() << "\n";
	else cout << "Niestety otwarcie drzwi w komorce " << model->PobierzBiezacaKomorke()->PobierzIndeks() << " nie powiodlo sie\n";
}

void Widok::WyswietlInformacjeOStanieGry() const
{
	switch(model->PobierzStanGry())
	{
	case Niezakonczona:
		break;
	case Umierasz:
		cout << "Zabiles sie z rozpaczy\n";
		break;
	case Wygrana:
		cout << "Dotarles do celu. Jestes zwyciezca!\n";
		break;
	}
}