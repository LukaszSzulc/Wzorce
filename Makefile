target all:
	test -d zad1/bin || mkdir -p zad1/bin
	clang++ -std=c++11 -stdlib=libstdc++ \
	zad1/src/BudowniczyLabiryntu.cpp \
	zad1/src/BudowniczyLabiryntuSingleton.cpp \
	zad1/src/FabrykaLabiryntu.cpp \
	zad1/src/FabrykaLabiryntuZPrototypami.cpp \
	zad1/src/Kontroler.cpp \
	zad1/src/Model.cpp \
	zad1/src/Widok.cpp \
	zad1/src/WzorceProjektowe_Labirynt.cpp \
	-o zad1/bin/zad1;
