#include "Widok.h"

#include <iostream>
using namespace std;

Widok::Widok(Labirynt* model)
	:model(model)
{	
}

void Widok::WyświetlInformacjęOKomórce(Komórka* komórka)
{
	cout << "Jestes w komorce " << komórka->PobierzIndeks() << ". Wybierz czynnosc (W, S, A, D, E)\n";	
}

void Widok::WyświetlInformacjęOBieżącejKomórce() const
{
	WyświetlInformacjęOKomórce(model->PobierzBieżącąKomórkę());
}

void Widok::WyświetlInformacjęOPróbiePrzejściaWKierunku(Kierunek kierunek)
{
	switch (kierunek)
	{
	case Zachód:
		cout << "Proba przejscia na zachod\n";
		break;
	case Wschód:
		cout << "Proba przejscia na wschod\n";
		break;
	case Północ:
		cout << "Proba przejscia na polnoc\n";
		break;
	case Południe:
		cout << "Proba przejscia na poludnie\n";
		break;
	}
}

void Widok::WyświetlInformacjęORezultaciePróbyPrzejścia(RezultatPróbyWejścia wynik) const
{
	switch (wynik)
	{
	case Powodzenie:
		cout << "Przechodzisz do komorki " << model->PobierzBieżącąKomórkę()->PobierzIndeks() << "\n";
		break;
	case Zamknięte:
		cout << "Niestety zamkniete. Musisz wpierw otworzyc\n";
		break;
	case NieMożnaWejść:
		cout << "Nie umiesz przechodzic przez sciany!\n";
		break;
	}
}

void Widok::WyświetlInformacjęOPróbieOtwarciaDrzwi() const
{
	cout << "Probujesz otworzyc wszystkie drzwi w komorce " <<
		model->PobierzBieżącąKomórkę()->PobierzIndeks() << "\n";
}

void Widok::WyświetlInformacjęORezultaciePróbyOtwarciaDrzwi(bool wynik) const
{
	if (wynik) cout << "Otworzyles wszystkie drzwi w komorce " <<
		model->PobierzBieżącąKomórkę()->PobierzIndeks() << "\n";
	else cout << "Niestety otwarcie drzwi w komorce " <<
		model->PobierzBieżącąKomórkę()->PobierzIndeks() <<
		" nie powiodlo sie\n";
}

void Widok::WyświetlInformacjęOStanieGry() const
{
	switch (model->PobierzStanGry())
	{
	case Niezakończona:
		break;
	case Śmierć:
		cout << "Zabiles sie z rozpaczy!\n";
		break;
	case Wygrana:
		cout << "Dotarles do celu!\n";
		break;
	}
}