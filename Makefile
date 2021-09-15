#-----------------------------------------#
#			COMPILER OPTIONS		
#-----------------------------------------#
CX		 = g++
EXT		 = cpp
CXFLAGS  = -std=c++14 -Wall -g
LIBS	 = -lsfml-graphics -lsfml-system -lsfml-window -lm
EXEC	 = main
DIR_OBJS = ./bin

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
	$(CX) $(CXFLAGS) $(OBJS) -o $(EXEC) $(LIBS)

# Builds .o's from .cpp's using automatic variables 
#	$<: the name of the prerequisite of the rule -> .cpp file 
#	$@: the name of the target of the rule 		 -> .o file
$(DIR_OBJS)/%.o : ./src/%.$(EXT)
	$(CX) $(CXFLAGS) -c $? -o $@

directory:
	mkdir -p $(DIR_OBJS)/

clean:
	rm -rf $(DIR_OBJS)
	rm $(EXEC)
	@echo Files deleted, project clean.