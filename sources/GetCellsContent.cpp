#include <iostream>
#include <vector>
#include <regex>
#include <LatexTypes.h>

//this function captures the cell content like text and index of style the same cell uses
void GetCellsContent(std::vector<lt::Cell> &cellVector, std::string &xmlContent, int nCells)
{
	std::string tmpString;  //elegido "(<table:table-cell).*?>"
	std::string tmpContent; //temporary store the content of a cell. 
	std::regex  regx("(<table:table-cell).*?/?>");//"(<table:table-cell).*?>");//<table:table-cell(.*?)\"(\\d)\"/>");//("<table:table-cell(.*?)\"(\\d*)\"");
	std::regex  regxSelector("repeated=\"(\\d+)\"");
	std::regex  expCellStyle("<table:table-cell table:style-name=\"ce(\\d.*?)\"/>");

	//std::regex  ncols("(columns-repeated=\"(\\d*)\")");
	std::string cadena;
	std::smatch iterable;
	std::smatch iterSelector;
	std::smatch iterContent;  //to capture the text content of cells.
	std::smatch iterNumbers;  //to capture the number of times an empty cell repeats.
	std::smatch iterSingleCell;
	std::smatch iterCellStyle; //to extract the style index the cell uses
    std::string::const_iterator searchStart( xmlContent.cbegin() );
    int nRepeats = 0;
    int index = 0;
    int vectorIndex = 0;


    while ( regex_search( searchStart, xmlContent.cend(), iterable, regx ) )
    {    
    	cadena = std::string(searchStart, xmlContent.cend());
    	tmpString = iterable[0].str();

    	//for empty cells and non-color
    	if(regex_search( tmpString, iterSelector, regxSelector))
    	{	
    		regex_search( tmpString, iterNumbers, std::regex("(\\d+)"));
    		//iterNumbers[0]  contains the number of times the cell is repeated on the row
    		nRepeats = std::stoi(iterNumbers[0].str());

    		//gets the style index for the cells
    		if(regex_search( tmpString, iterCellStyle, expCellStyle))
    			index = std::stoi(iterCellStyle[1].str());
    		else
    			index = 0; //the default style (an empty style)

    		//assign the empty cell and style index if has anyone
    		for(int i=0; i < nRepeats; i++)
    		{
    			cellVector[vectorIndex + i].indexStyle = index;
    			cellVector[vectorIndex + i].content = "";  //cambiar por " "
    		}
    		vectorIndex += nRepeats-1;

    	}//end if												celda vacía sin ningún estilo												//celda con vacía con algún estilo
    	else if(regex_search( tmpString, iterSingleCell, std::regex("<table:table-cell/>")) || regex_search( tmpString, iterSingleCell, std::regex("<table:table-cell table:style-name=\"ce(\\d.*?)\"/>"))) //for single empty cells with or without background color
    	{
    		cellVector[vectorIndex].content = "";

    		//check if the cell has any style
    		if(regex_search( tmpString, iterCellStyle, expCellStyle))
    			index = std::stoi(iterCellStyle[1].str());
    		else
    			index = 0; //the default style (an empty style)

    		cellVector[vectorIndex].indexStyle = index;
    		cellVector[vectorIndex].content = "";
    	}//end if-else
    	else 
    	{
    		if(regex_search( searchStart+iterable[0].length(), xmlContent.cend(), iterContent, std::regex("p>(.*?)</") ))
 		   			tmpContent = iterContent[1].str();
    		else
    			std::cout<<"no captura el texto"<<std::endl;

    		//check if the cell has any style
    		tmpString = iterable[0].str();
    		if(regex_search( tmpString, iterCellStyle, expCellStyle))
    			index = std::stoi(iterCellStyle[1].str());
    		else
    			index = 0; //the default style (an empty style)

    		cellVector[vectorIndex].indexStyle = index;
    		cellVector[vectorIndex].content = tmpContent;
    	}	
        searchStart += iterable.position() + iterable[0].length();
        vectorIndex++;
    }
}
