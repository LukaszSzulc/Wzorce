#include "Kontroler.h"
#ifdef _WIN32
#include <conio.h> //_getch
#else
#include "linuxConio.h"
#endif

void Kontroler::SpróbujPrzejść(Kierunek kierunek)
{
	Widok::WyświetlInformacjęOPróbiePrzejściaWKierunku(kierunek);
	RezultatPróbyWejścia wynik = model->PrzejdźWKierunku(kierunek);
	widok->WyświetlInformacjęORezultaciePróbyPrzejścia(wynik);
}

void Kontroler::SpróbujOtworzyćDrzwi()
{
	widok->WyświetlInformacjęOPróbieOtwarciaDrzwi();
	bool wynik = model->PobierzBieżącąKomórkę()->OtwórzDrzwi();
	widok->WyświetlInformacjęORezultaciePróbyOtwarciaDrzwi(wynik);
}

void Kontroler::Uruchom()
{
	bool zakończ = false;
	do
	{
		widok->WyświetlInformacjęOBieżącejKomórce();
		int kodKlawisza = _getch();
		//std::cout << "Kod nacisnietego klawisza: " << kodKlawisza << "\n";

		switch(kodKlawisza)
		{
		case 97:
		case 75:
			//przesuń na zachód
			SpróbujPrzejść(Zachód);
			break;
		case 100:
		case 77:
			//przesuń na wschód
			SpróbujPrzejść(Wschód);
			break;
		case 119:
		case 72:
			//przesuń na północ
			SpróbujPrzejść(Północ);
			break;
		case 115:
		case 80:
			//przesuń na południe
			SpróbujPrzejść(Południe);
			break;
		case 101:
			SpróbujOtworzyćDrzwi();
			break;
		case 27:
			model->Zakończ();
			break;
		}

		widok->WyświetlInformacjęOStanieGry();
		if(model->PobierzStanGry()!=Niezakończona) zakończ = true;
	}
	while(!zakończ);
}
