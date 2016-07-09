#Makefile to compile the entire project

.PHONY: all clan
SRC_DIR    = ./sources/   #sources folder containing all .cpp files
HDR_DIR    = ./headers/   #headers folder containing all .h   files

OBJS       = main.o ReadXmlFile.o ChangeExt.o
OBJS_MAIN  = ReadXmlFile.o ChangeExt.o

all: $(OBJS)
	g++ -Wall $(OBJS) -o LatexTables

main.o: ./sources/main.cpp $(OBJS_MAIN)
	g++ -Wall -c -I./headers/ $< -o $@ 

ReadXmlFile.o:  ./sources/ReadXmlFile.cpp
	g++ -Wall -c $< -o $@ 

ChangeExt.o:    ./sources/ChangeExt.cpp
	g++ -Wall -c $< -o $@


clean:
	rm $(OBJS)








