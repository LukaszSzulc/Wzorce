#include "FabrykaLabiryntuZPrototypami.h"

Komórka* FabrykaLabiryntuZPrototypami::TwórzKomórkę(int indeks) const 
{ 
	Komórka* komórka = prototypKomórki->Klonuj(); 
	komórka->Inicjuj(indeks);
	return komórka;
}

Ściana* FabrykaLabiryntuZPrototypami::TwórzŚcianę() const 
{ 
	return prototypŚciany->Klonuj(); 
}

Drzwi* FabrykaLabiryntuZPrototypami::TwórzDrzwi(int indeksKomórki1, int indeksKomórki2) const
{ 
	Drzwi* drzwi = prototypDrzwi->Klonuj(); 
	drzwi->Inicjuj(indeksKomórki1, indeksKomórki2);
	return drzwi;
}

//------------------------------------------------

Labirynt* StandardowaFabrykaLabiryntuZPrototypami::TwórzLabirynt() const
{
	const int liczbaKomórek = 15;
	Labirynt* labirynt = new Labirynt(liczbaKomórek, 0, 14);
	PKomórka* komórki = new PKomórka[liczbaKomórek];
	for (int i = 0; i < liczbaKomórek; i++) komórki[i] = TwórzKomórkę(i);

	komórki[0]->PowiążZMiejscem(Wschód, komórki[1]);
	komórki[1]->PowiążZMiejscem(Zachód, komórki[0]);

	komórki[1]->PowiążZMiejscem(Wschód, komórki[2]);
	komórki[2]->PowiążZMiejscem(Zachód, komórki[1]);

	komórki[2]->PowiążZMiejscem(Południe, komórki[3]);
	komórki[3]->PowiążZMiejscem(Północ, komórki[2]);

	komórki[3]->PowiążZMiejscem(Wschód, komórki[4]);
	komórki[4]->PowiążZMiejscem(Zachód, komórki[3]);

	komórki[4]->PowiążZMiejscem(Wschód, komórki[5]);
	komórki[5]->PowiążZMiejscem(Zachód, komórki[4]);

	komórki[3]->PowiążZMiejscem(Południe, komórki[6]);
	komórki[6]->PowiążZMiejscem(Północ, komórki[3]);

	komórki[4]->PowiążZMiejscem(Południe, komórki[7]);
	komórki[7]->PowiążZMiejscem(Północ, komórki[4]);

	komórki[5]->PowiążZMiejscem(Południe, komórki[8]);
	komórki[8]->PowiążZMiejscem(Północ, komórki[5]);

	komórki[6]->PowiążZMiejscem(Wschód, komórki[7]);
	komórki[7]->PowiążZMiejscem(Zachód, komórki[6]);

	komórki[7]->PowiążZMiejscem(Wschód, komórki[8]);
	komórki[8]->PowiążZMiejscem(Zachód, komórki[7]);

	Drzwi* drzwi_6_10 = TwórzDrzwi(6, 10);
	komórki[6]->PowiążZMiejscem(Południe, drzwi_6_10);
	komórki[10]->PowiążZMiejscem(Północ, drzwi_6_10);

	komórki[10]->PowiążZMiejscem(Zachód, komórki[9]);
	komórki[9]->PowiążZMiejscem(Wschód, komórki[10]);

	komórki[9]->PowiążZMiejscem(Południe, komórki[11]);
	komórki[11]->PowiążZMiejscem(Północ, komórki[9]);

	komórki[11]->PowiążZMiejscem(Wschód, komórki[12]);
	komórki[12]->PowiążZMiejscem(Zachód, komórki[11]);

	komórki[12]->PowiążZMiejscem(Wschód, komórki[13]);
	komórki[13]->PowiążZMiejscem(Zachód, komórki[12]);

	komórki[13]->PowiążZMiejscem(Wschód, komórki[14]);
	komórki[14]->PowiążZMiejscem(Zachód, komórki[13]);

	for (int i = 0; i < liczbaKomórek; ++i) labirynt->DodajKomórkę(i, komórki[i]);
	delete[] komórki; //usuwa tablicę, ale nie elementy
	return labirynt;
}
