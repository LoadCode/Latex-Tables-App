#include <iostream>
#include <fstream>

/*This function return only the  last (the important) line of the content.xml file*/
/*input: A std::string containing the fileName 									  */
/*input: A std::string & to a string in the function from readXmlFile was called  */
/*bool return:  <false> if failing opening the file 							  */
/*				<true>  if read was successfully   								  */
/*This method works for absolute and relative paths (i.e. ./content.xml)          */

bool ReadXmlFile(std::string fileName, std::string &tmp) 
{
	std::ifstream inputStream;
	inputStream.open(fileName,std::ifstream::in);
	
	if(inputStream.fail())  //returns false if fails on openingto open
		return false;
	while(!inputStream.eof())
	{
		std::getline(inputStream, tmp);
	}	

	inputStream.close();
	return true;
}











