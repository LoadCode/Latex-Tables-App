#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <string>




//Retorna la cantidad de filas que posee el archivo .odf
//realiza un recorrido del contenido de xmlContent buscando 
//coincidencias
int TableNumberRows(std::string &xmlContent)
{
	int nRows = 0;
	std::regex  regx("(<table:table-row)");
	std::smatch iterable;
    std::string::const_iterator searchStart( xmlContent.cbegin() );

    while ( regex_search( searchStart, xmlContent.cend(), iterable, regx ) )
    {
        searchStart += iterable.position() + iterable.length();
        nRows++;
    }
	
	return nRows;
}