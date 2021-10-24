#-----------------------------------------#
#			COMPILER OPTIONS		
#-----------------------------------------#
CX		 = g++
CXFLAGS  = -std=c++14 -Wall
EXT		 = cpp
LIBS	 = -lsfml-graphics -lsfml-system -lsfml-window -lm
DIR_OBJS = ./bin
EXEC	 = main

#-----------------------------------------#
#				FILES    		
#-----------------------------------------#
SRC := $(shell echo src/*.$(EXT))

#notdir    : returns the file only without its folder (src/main.c 	 -> main.c)
#basename  : returns the file withtout its suffix     (main.c     	 -> main)
#addprefix : returns the file with its new prefix     (main 	  	 -> DIR_OBJS/main)
#addsuffix : returns the file with its new suffix     (DIR_OBJS/main -> DIR_OBJS/main.o)
OBJS = $(addsuffix .o, $(addprefix $(DIR_OBJS)/, $(basename $(notdir $(SRC)))))

#-----------------------------------------#
#	       	COMPILING RULES	      
#-----------------------------------------#
all: $(EXEC)
	@echo Project compiled !

$(EXEC): directory $(OBJS) 
	$(CX) $(CXFLAGS) $(OBJS) -o $(DIR_OBJS)/$(EXEC) $(LIBS)

# Builds .o's from .cpp's using automatic variables 
#	$<: the name of the prerequisite of the rule -> .cpp file 
#	$@: the name of the target of the rule 		 -> .o file
$(DIR_OBJS)/%.o : ./src/%.$(EXT)
	$(CX) $(CXFLAGS) -c $< -o $@

directory:
	mkdir -p $(DIR_OBJS)/

clean:
	rm -rf $(DIR_OBJS)
	@echo Files deleted, project clean.