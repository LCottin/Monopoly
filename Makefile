CC 		= g++
CFLAGS 	= -std=c++14 -Wall
SFML	= -lsfml-graphics -lsfml-system -lsfml-window
EXEC	= main

SRC = ./src/main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean : 
	rm -rf ./src/*.o
	rm $(EXEC)
