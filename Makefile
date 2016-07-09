#Makefile to compile the entire project

.PHONY: all clean

OBJS       = main.o ReadXmlFile.o ChangeExt.o FileExistenceValidation.o UnzipFile.o
OBJS_MAIN  = ReadXmlFile.o ChangeExt.o FileExistenceValidation.o UnzipFile.o


all: $(OBJS)
	g++ -Wall $(OBJS) -o LatexTables

main.o: ./sources/main.cpp $(OBJS_MAIN)
	g++ -Wall -c -I./headers/ $< -o $@ 

ReadXmlFile.o:  ./sources/ReadXmlFile.cpp
	g++ -Wall -c $< -o $@ 

ChangeExt.o:    ./sources/ChangeExt.cpp
	g++ -Wall -c $< -o $@

FileExistenceValidation.o:  ./sources/FileExistenceValidation.cpp
	g++ -Wall -c $< -o $@

UnzipFile.o: ./sources/UnzipFile.cpp
	g++ -Wall -c $< -o $@

clean:
	rm $(OBJS)








