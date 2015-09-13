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

	test -d zad3/bin || mkdir -p zad3/bin
	clang++ -std=c++11 -stdlib=libstdc++ \
	zad3/src/BudowniczyLabiryntu.cpp \
	zad3/src/BudowniczyLabiryntuSingleton.cpp \
	zad3/src/FabrykaLabiryntu.cpp \
	zad3/src/FabrykaLabiryntuZPrototypami.cpp \
	zad3/src/Kontroler.cpp \
	zad3/src/Model.cpp \
	zad3/src/Widok.cpp \
	zad3/src/WzorceProjektowe_Labirynt.cpp \
	-o zad3/bin/zad3;

	test -d zad4/bin || mkdir -p zad4/bin
	clang++ -std=c++11 -stdlib=libstdc++ \
	zad4/src/singleton.cpp \
	-o zad4/bin/zad4;

	test -d zad5/bin || mkdir -p zad5/bin
	clang++ -std=c++11 -stdlib=libstdc++ \
	zad5/src/iterator.cpp \
	-o zad5/bin/zad5;
