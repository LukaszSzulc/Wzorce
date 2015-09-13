#include "FabrykaLabiryntuZPrototypami.h"

Komorka* FabrykaLabiryntuZPrototypami::TworzKomorke(int indeks) const
{
	Komorka* Komorka = prototypkomorki->Klonuj();
	Komorka->Inicjuj(indeks);
	return Komorka;
}

Sciana* FabrykaLabiryntuZPrototypami::TworzSciane() const
{
	Sciana* Sciana = prototypSciany->Klonuj();	
	return Sciana;
}

Drzwi* FabrykaLabiryntuZPrototypami::TworzDrzwi(int indekskomorki1, int indekskomorki2) const
{
	Drzwi* drzwi = prototypDrzwi->Klonuj();
	drzwi->Inicjuj(indekskomorki1, indekskomorki2);
	return drzwi;
}

Labirynt* StandardowaFabrykaLabiryntuZPrototypami::TworzLabirynt() const
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
