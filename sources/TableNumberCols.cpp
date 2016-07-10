#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <string>



//Retorna la cantidad de columnas que posee el archivo .odf
//realiza un recorrido del contenido de xmlContent buscando 
//coincidencias
int TableNumberCols(std::string &xmlContent)
{
	int singleCols = 0;
	std::string tmpString;
	std::regex  regx("(table:table-column)(.*?)?(\"Default\"/>)");
	std::regex  ncols("(columns-repeated=\"(\\d*)\")");
	std::smatch iterCols;
	std::smatch iterable;
    std::string::const_iterator searchStart( xmlContent.cbegin() );

    while ( regex_search( searchStart, xmlContent.cend(), iterable, regx ) )
    {    	
    	tmpString = iterable[0].str();
     	//tries to find the number of times a column style repeats
    	if(std::regex_search( tmpString, iterCols, ncols) )  
    		singleCols += std::stoi(iterCols[2].str());
    	else
    		singleCols++;
        searchStart += iterable.position() + iterable.length();
    }
	
	return singleCols;
}


