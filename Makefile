HEADER_FILES = main.hpp game_state.hpp ./game_state_start.hpp ./game_state_editor.hpp
SOURCE_FILES = main.cpp game_state.cpp ./game_state_start.cpp ./game_state_editor.cpp

SFML_DEPENDENCIES = -lsfml-graphics -lsfml-window -lsfml-system

sfml-app: main.cpp
	g++ -c HEADER_FILES SOURCE_FILES
	g++ main.o -o sfml-app SFML_DEPENDENCIES
