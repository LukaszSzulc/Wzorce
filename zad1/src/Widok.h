#pragma once

#include "Model.h"

#define WIDTH 20
#define HEIGHT 10

class Widok
{
private:
	Labirynt* model;
	char display[WIDTH][HEIGHT];

public:
	Widok(Labirynt* model);

	static void WyświetlInformacjęOKomórce(Komórka* komórka);
	void WyświetlInformacjęOBieżącejKomórce();
	static void WyświetlInformacjęOPróbiePrzejściaWKierunku(Kierunek kierunek);
	void WyświetlInformacjęORezultaciePróbyPrzejścia(RezultatPróbyWejścia wynik) const;
	void WyświetlInformacjęOPróbieOtwarciaDrzwi() const;
	void WyświetlInformacjęORezultaciePróbyOtwarciaDrzwi(bool wynik) const;
	void WyświetlInformacjęOStanieGry() const;
	void WyświetlLabirynt(Komórka* komorka);
	void WyświetlWejdźWKomórkę(Komórka* komórka, int x, int y);
	static char GraficznaReprezentacjaŚciany(RezultatPróbyWejścia rezultat);
};
