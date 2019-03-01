SOURCE_FILES = ./src/main.cpp ./src/game.cpp ./src/devve.cpp
HEADER_FILES = ./headers/main.h ./headers/game.h ./headers/devve.h

DEPENDENCIES = -lsfml-graphics -lsfml-window -lsfml-system

main: $(SOURCE_FILES) $(HEADER_FILES)
	clear
	g++ -w -I ./headers -c main $(SOURCE_FILES) $(HEADER_FILES)
	g++ main.o -o main $(DEPENDENCIES)
	rm *.gch *.o
