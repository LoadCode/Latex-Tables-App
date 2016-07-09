#include <iostream>
#include <fstream>

/*This function veriefies the existence of the file defined by  */
/*fileName														*/
/*Return:  true  -> if the file exist      						*/
/*Return:  false -> the file can't be found						*/


bool FileExistenceValidation(std::string &fileName)
{
	
	std::ifstream inputStream;
	inputStream.open(fileName,std::ifstream::in);
	
	if(inputStream.fail())  //returns false if fails on opening the file
		return false;   
	
	inputStream.close();
	return true;
}