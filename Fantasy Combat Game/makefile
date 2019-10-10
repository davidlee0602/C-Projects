all: fantasy

fantasy: main.o Menu.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o
	g++ -std=c++11 main.o Menu.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o -o fantasy

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Menu.o: Menu.cpp
	g++ -std=c++11 -c Menu.cpp

Character.o: Character.cpp
	g++ -std=c++11 -c Character.cpp

Vampire.o: Vampire.cpp
	g++ -std=c++11 -c Vampire.cpp

Barbarian.o: Barbarian.cpp
	g++ -std=c++11 -c Barbarian.cpp

BlueMen.o: BlueMen.cpp
	g++ -std=c++11 -c BlueMen.cpp

Medusa.o: Medusa.cpp
	g++ -std=c++11 -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -std=c++11 -c HarryPotter.cpp

zip:
	zip Project3_Lee_David.zip -D *.cpp *.hpp *.pdf makefile 

clean:
	rm *.o fantasy