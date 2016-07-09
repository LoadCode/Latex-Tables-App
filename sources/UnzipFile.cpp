#include <iostream>
#include <cstdlib>


/*This function interacts with the .zip file created by ChangeExt method    */
/*Unzip the file passed to it, interacts with the OS, make use of the unzip */
/*utiliti on the os terminal 												*/

bool UnzipFile(std::string OdfFileName)
{
	std::string cmd("unzip ");      //Command to unzip files
	std::string subDir(" ./.temp"); //the content will be placed into temporary folder
	std::string cmdLine;			//Line to be executed
	std::string newFile = OdfFileName;
	std::string oldExt(".odf");
	std::string newExt(".zip");

	//creates a new fileName with extension .zip
  	std::string::size_type pos = newFile.find(oldExt, 0);
  	if (pos < std::string::npos)
    	newFile.replace(pos, std::string(oldExt).length(), newExt);    
	
	cmdLine = cmd + newFile + std::string(" -d") + subDir;

	if(std::system(cmdLine.c_str()) == 0)
		return true;    //On success
	else
		return false;   //On failure
}



