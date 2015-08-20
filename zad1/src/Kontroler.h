#pragma once

#include "Widok.h"
#include "BudowniczyLabiryntu.h"
#include "Model.h"
//#include "FabrykaLabiryntu.h"
//#include "FabrykaLabiryntuZPrototypami.h"
//#include "BudowniczyLabiryntuSingleton.h"

class Kontroler
{
protected:
	Labirynt* model;
	Widok* widok;

	void SpróbujPrzejść(Kierunek kierunek);
	void SpróbujOtworzyćDrzwi();

public:
	Kontroler(void)
	{
		//model = TwórzLabirynt();

		//budowniczy
		StandardowyBudowniczyLabiryntu budowniczy;
		model = ::TwórzLabirynt(budowniczy);

		//metoda wytworcza
		//StandardowaFabrykaLabiryntu fabryka;
		//model = fabryka.TwórzLabirynt();

		//prototyp
		//Komórka wzorcowaKomórka(-1);
		//Ściana wzorcowaŚciana;
		//Drzwi wzorcoweDrzwi(-1, -1);
		//StandardowaFabrykaLabiryntuZPrototypami fabryka(&wzorcowaKomórka, &wzorcowaŚciana, &wzorcoweDrzwi);
		//model = fabryka.TwórzLabirynt();

		//Singleton
		//BudowniczyLabiryntuSingleton* budowniczy = StandardowyBudowniczyLabiryntuSingleton::PobierzStandardowegoBudowniczegoLabiryntu();
		//model = ::TwórzLabirynt(*budowniczy);

		widok = new Widok(model);
	}

	~Kontroler(void)
	{
		delete widok;
		delete model;
	}

	void Uruchom();
};
