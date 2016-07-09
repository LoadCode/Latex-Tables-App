#Makefile to compile the entire project

.PHONY: all clan
SRC_DIR = ./sources/   #sources folder containing all .cpp files
HDR_DIR = ./headers/   #headers folder containing all .h   files

OBJS    = fileHandler.o main.o

all: $(OBJS)
	g++ -Wall $(OBJS) -o LatexTables

main.o: ./sources/main.cpp fileHandler.o
	g++ -Wall -c -I./headers/ $< -o $@ 

fileHandler.o:  ./sources/fileHandler.cpp
	g++ -Wall -c  $< -o $@ 



clean:
	rm $(OBJS)








