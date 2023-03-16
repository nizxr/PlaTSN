# Compiler settings
EXEC_NAMES = bin/cb 
OBJS = obj/Pixel.o

GCC = g++
FLAGS = -Wall -ggdb

LIBS = -lSDL2 -lSDL2_image -lSDL2_image
INCLUDE = -ISDL2

RM = rm -rf

# Makefile settings

########################################################################
####################### Targets beginning here #########################
########################################################################
all: $(EXEC_NAMES)

bin/cb: $(OBJS) obj/Affichage.o
	$(GCC) $(FLAGS) $(OBJS) obj/Affichage.o -o bin/cb $(LIBS)

obj/Affichage.o: src/CasseBrique/core/Affichage.cpp src/CasseBrique/core/Pixel.h
	$(GCC) $(FLAGS) -c src/CasseBrique/core/Affichage.cpp -o obj/Affichage.o $(INCLUDE)

obj/Pixel.o: src/CasseBrique/core/Pixel.cpp src/CasseBrique/core/Pixel.h
	$(GCC) $(FLAGS) -c src/CasseBrique/core/Pixel.cpp -o obj/Pixel.o $(INCLUDE)

clean:
	$(RM) bin/* obj/*
