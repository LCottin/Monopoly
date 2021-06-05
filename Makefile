CC 		= g++
CFLAGS 	= -std=c++14 -Wall 
LIBS	= -lsfml-graphics -lsfml-system -lsfml-window -lm
EXEC	= main

SRC = 	./src/main.cpp \
		./src/Dice.cpp \
		./src/Bank.cpp \
		./src/Piece.cpp \
		./src/Player.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXEC)
	@echo  Project compiled !

$(EXEC): $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LIBS)

# Builds .o's from .c's
# It uses automatic variables 
#	$<: the name of the prerequisite of the rule(a .c file)  
#	$@: the name of the target of the rule (a .o file) 
.cpp.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm -rf ./src/*.o
	rm $(EXEC)
	@echo Files deleted

