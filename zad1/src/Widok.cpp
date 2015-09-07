#include "Widok.h"

#include <iostream>
using namespace std;

// 1 - wyświetl tylko obecna komorke
// 2 - wyświetl cały labirynt
#define VIEW_MODE 2
//#define VIEW_MODE 2

void clear_screen()
{
	#ifdef WINDOWS
	std::system("cls");
	#else
	// Assume POSIX
	std::system ("clear");
	#endif
}

Widok::Widok(Labirynt* model)
	:model(model)
{
}

void Widok::WyświetlWejdźWKomórkę(Komórka* komórka, int x, int y) {
	MiejsceWLabiryncie* polnoc = komórka->PobierzMiejscePoStronie(Północ);
	MiejsceWLabiryncie* poludnie = komórka->PobierzMiejscePoStronie(Południe);
	MiejsceWLabiryncie* wschod = komórka->PobierzMiejscePoStronie(Wschód);
	MiejsceWLabiryncie* zachod = komórka->PobierzMiejscePoStronie(Zachód);

	RezultatPróbyWejścia wejPolnoc = polnoc->SpróbujWejść();
	RezultatPróbyWejścia wejPoludnie = poludnie->SpróbujWejść();
	RezultatPróbyWejścia wejWschod = wschod->SpróbujWejść();
	RezultatPróbyWejścia wejZachod = zachod->SpróbujWejść();

	if (display[x][y] != ' ') return;
	display[x][y] = '.';

	if (wejPolnoc == Powodzenie) WyświetlWejdźWKomórkę((Komórka*) polnoc, x, y-1);
	if (wejPoludnie == Powodzenie) WyświetlWejdźWKomórkę((Komórka*) poludnie, x, y+1);

	if (wejWschod == Powodzenie) WyświetlWejdźWKomórkę((Komórka*) wschod, x+1, y);
	if (wejZachod == Powodzenie) WyświetlWejdźWKomórkę((Komórka*) zachod, x-1, y);

	//cout << polnoc << ", " << poludnie << ", " << wschod << ", " << zachod << "\n";
}

void Widok::WyświetlLabirynt(Komórka* komórka)
{
	int centerX = WIDTH/2;
	int centerY = HEIGHT/2;

	for (int i = 0; i < WIDTH; ++i)
		for (int j = 0; j < HEIGHT; ++j)
			display[i][j] = ' ';

	WyświetlWejdźWKomórkę(komórka, centerX, centerY);
	display[centerX][centerY] = '#';

	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
				std::cout << display[j][i];
			}
			std::cout << "\n";
	}
}

char Widok::GraficznaReprezentacjaŚciany(RezultatPróbyWejścia rezultat)
{
	switch (rezultat) {
		case Powodzenie:
			return ' ';

		case NieMożnaWejść:
			return '*';

		case Zamknięte:
			return '#';
	}
}

void Widok::WyświetlInformacjęOKomórce(Komórka* komórka)
{
	cout << "Jestes w komorce " << komórka->PobierzIndeks() << ". Wybierz czynnosc (W, S, A, D, E)\n";

	MiejsceWLabiryncie* polnoc = komórka->PobierzMiejscePoStronie(Północ);
	RezultatPróbyWejścia wejPolnoc = polnoc->SpróbujWejść();

	MiejsceWLabiryncie* poludnie = komórka->PobierzMiejscePoStronie(Południe);
	RezultatPróbyWejścia wejPoludnie = poludnie->SpróbujWejść();

	MiejsceWLabiryncie* wschod = komórka->PobierzMiejscePoStronie(Wschód);
	RezultatPróbyWejścia wejWschod = wschod->SpróbujWejść();

	MiejsceWLabiryncie* zachod = komórka->PobierzMiejscePoStronie(Zachód);
	RezultatPróbyWejścia wejZachod = zachod->SpróbujWejść();

	const string padding = "    ";

	cout << "Mapa obecnej komorki:\n\n";
	cout << padding << " " << GraficznaReprezentacjaŚciany(wejPolnoc) << "\n";
	cout << padding << GraficznaReprezentacjaŚciany(wejZachod) << " " << GraficznaReprezentacjaŚciany(wejWschod) << "\n";
	cout << padding << " " << GraficznaReprezentacjaŚciany(wejPoludnie) << "\n";
}


void Widok::WyświetlInformacjęOBieżącejKomórce()
{
	#if VIEW_MODE == 2
	WyświetlLabirynt(model->PobierzBieżącąKomórkę());
	#else
	WyświetlInformacjęOKomórce(model->PobierzBieżącąKomórkę());
	#endif
}

void Widok::WyświetlInformacjęOPróbiePrzejściaWKierunku(Kierunek kierunek)
{
	clear_screen();
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
