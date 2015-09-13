#pragma once

#include "Model.h"
#include "Widok.h"
//#include "BudowniczyLabiryntu.h"
//#include "FabrykaLabiryntu.h"
//#include "FabrykaLabiryntuZPrototypami.h"
#include "BudowniczyLabiryntuSingleton.h"

class Kontroler
{
protected:
	Labirynt* model;
	Widok* widok;

	void SprobujPrzejsc(Kierunek kierunek);
	void SpróbujOtworzycDrzwi();

public:
	Kontroler(void)
	{
		//model = TworzLabirynt();

		//budowniczy
		/*
		StandardowyBudowniczyLabiryntu budowniczy;
		model = TworzLabirynt(budowniczy);
		*/

		//metoda wytwórcza
		//model = TworzLabirynt();

		//fabryka abstrakcyjna
		//StandardowaFabrykaLabiryntu fabryka;
		//model = fabryka.TworzLabirynt();

		//prototyp
		/*
		Komorka protypkomorki(-1);
		Sciana prototypSciany;
		Drzwi prototypDrzwi(-1,-1);
		StandardowaFabrykaLabiryntuZPrototypami fabryka(&protypkomorki,&prototypSciany,&prototypDrzwi);
		model = fabryka.TworzLabirynt();
		*/

		//Singleton
		BudowniczyLabiryntuSingleton* budowniczy = BudowniczyLabiryntuSingleton::PobierzStandardowegoBudowniczegoLabiryntu();
		model = TworzLabirynt(*budowniczy);

		widok = new Widok(model);
	}

	~Kontroler(void)
	{
		delete widok;
		delete model;
	}

	void Uruchom();

	/*
	//metody wytwórcze
	static Komorka* TworzKomorke(int indeks);
	static Drzwi* TworzDrzwi(int indekskomorki1, int indekskomorki2);
	static Labirynt* TworzLabirynt();
	*/
};

