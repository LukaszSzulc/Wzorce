#pragma once

#include "Model.h"

class Widok
{
private:
	Labirynt* model;

public:
	Widok(Labirynt* model);

	static void WyświetlInformacjęOKomórce(Komórka* komórka);
	void WyświetlInformacjęOBieżącejKomórce() const;
	static void WyświetlInformacjęOPróbiePrzejściaWKierunku(Kierunek kierunek);
	void WyświetlInformacjęORezultaciePróbyPrzejścia(RezultatPróbyWejścia wynik) const;
	void WyświetlInformacjęOPróbieOtwarciaDrzwi() const;
	void WyświetlInformacjęORezultaciePróbyOtwarciaDrzwi(bool wynik) const;
	void WyświetlInformacjęOStanieGry() const;
};

