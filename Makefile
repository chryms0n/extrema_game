sfml-app: main.cpp
	g++ -c main.cpp gamestate.hpp
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
