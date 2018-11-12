HEADER_FILES = ./main.hpp game_state.hpp ./game_state_start.hpp ./game_state_editor.hpp animation.hpp ./texture_manager.hpp
SOURCE_FILES = ./main.cpp game_state.cpp ./game_state_start.cpp ./game_state_editor.cpp texture_manager.cpp
OBJECT_FILES = ./main.o ./game_state.o ./game_state_start.o ./game_state_editor.o ./texture_manager.o 

SFML_DEPENDENCIES = -lsfml-graphics -lsfml-window -lsfml-system

sfml-app: main.cpp
	
	clear
	#g++ -c $(HEADER_FILES) $(SOURCE_FILES)
	#g++ $(OBJECT_FILES) -o sfml-app $(SFML_DEPENDENCIES)
	g++ -o sfml-app $(HEADER_FILES) $(SOURCE_FILES) $(SFML_DEPENDENCIES)

Main: $(HEADER_FILES) $(SOURCE_FILES)
	clear
	g++ -o Main $(HEADER_FILES) $(SOURCE_FILES) $(SFML_DEPENDENCIES)


all: test.cpp
	
	clear
	g++ -c test.cpp test.hpp
	g++ test.o -o test


clean:
	rm *.o *.gch
