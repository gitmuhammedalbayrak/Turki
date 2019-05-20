derle:topla

topla:main.o zaman.o pugixml.o
	g++ ./lib/main.o ./lib/Zaman.o ./lib/pugixml.o -o Turki

main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
zaman.o:
	g++ -I "./include" -c ./src/zaman.cpp -o ./lib/zaman.o
pugixml.o:
	g++ -I "./include" -c ./src/pugixml.cpp -o ./lib/pugixml.o