
HEADER_FILES = main.hpp game_state.hpp ./game_state_start.hpp ./game_state_editor.hpp
SOURCE_FILES = main.cpp game_state.cpp ./game_state_start.cpp ./game_state_editor.cpp

SFML_DEPENDENCIES = -lsfml-graphics -lsfml-window -lsfml-system

sfml-app: main.cpp
	
	clear
	g++ -c HEADER_FILES SOURCE_FILES
	g++ main.o -o sfml-app SFML_DEPENDENCIES

test: test.cpp
	
	clear
	g++ -c test.cpp test.hpp
	g++ test.o -o test
