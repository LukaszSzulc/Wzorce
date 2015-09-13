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

	test -d zad2/bin || mkdir -p zad2/bin
	clang++ -std=c++11 -stdlib=libstdc++ \
	zad2/src/BudowniczyLabiryntu.cpp \
	zad2/src/BudowniczyLabiryntuSingleton.cpp \
	zad2/src/FabrykaLabiryntu.cpp \
	zad2/src/FabrykaLabiryntuZPrototypami.cpp \
	zad2/src/Kontroler.cpp \
	zad2/src/Model.cpp \
	zad2/src/Widok.cpp \
	zad2/src/WzorceProjektowe_Labirynt.cpp \
	-o zad2/bin/zad2;

	test -d zad4/bin || mkdir -p zad4/bin
	clang++ -std=c++11 -stdlib=libstdc++ \
	zad4/src/singleton.cpp \
	-o zad4/bin/zad4;
