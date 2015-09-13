#pragma once
#include "Model.h"

class Widok
{
private:
	Labirynt* model;

public:
	Widok(Labirynt* model);
	
	static void WyswietlInformacjeOKomorce(Komorka* Komorka);
	void WyswietlInformacjeOBiezacejKomorce() const;
	static void WyswietlInformacjeOProbiePrzejsciaWKierunku(Kierunek kierunek);
	void WyswietlInformacjeORezultacieProbyPrzejscia(RezultatProbyWejscia wynik) const;
	void WyswietlInformacjeOProbieOtwarciaDrzwi() const;
	void WyswietlInformacjeORezultacieProbyOtwarciaDrzwi(bool wynik) const;
	void WyswietlInformacjeOStanieGry() const;
};

