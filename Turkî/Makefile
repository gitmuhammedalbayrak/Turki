derle:topla

topla:main.o Zaman.o pugixml.o
	g++ ./lib/main.o ./lib/Zaman.o ./lib/pugixml.o -o Turki

main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
Zaman.o:
	g++ -I "./include" -c ./src/Zaman.cpp -o ./lib/Zaman.o
pugixml.o:
	g++ -I "./include" -c ./src/pugixml.cpp -o ./lib/pugixml.o