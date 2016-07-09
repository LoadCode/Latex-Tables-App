#include <iostream>
#include <cstdlib>  //to use the function system()


/*This function uses the <cmd> command on linux to change de the extension     */
/*of the *.<oldExt> and sets *.<newExt> extension to the file. 				         */
/*By deafult, this function tries to change the extension of a filename with   */
/*.odf extension and leave it as a .zip file 								                   */
/*Returns true if command executes succssefully, false in other case.		       */
/*Note: <cmd> must finish with white-space for concatenation purpouses         */

bool ChangeExt(std::string fileName, std::string cmd = std::string("mv "),\
std::string oldExt = std::string(".odf"), std::string newExt = std::string(".zip"))
{
  std::string newFile = fileName;
  std::string comLine;                  //oldExt=.somthing
  std::string::size_type pos = newFile.find(oldExt, 0);

  //creates a new fileName with extension .zip
  if (pos < std::string::npos)
    newFile.replace(pos, std::string(oldExt).length(), newExt);    
  else
    return false;  //Cause old extension wheren't found

  //Compose the command line to execute
  comLine = cmd + fileName + std::string(" ") + newFile;

  
  //the function returns 0 if go well, non-zero value if something goes wrong
  if(system(comLine.c_str()) == 0)
    return true;
  else
    return false;
}



/****************************HOW TO USE THIS FUNCTION**************************/
/*
int main (int nargs, char * args[])
{
  std::string fileName(args[1]);
  std::string cmd("mv ");
  std::string oldExt(".zip");
  std::string newExt(".odf");

  if(ChangeExt(fileName, cmd, oldExt, newExt))
    std::cout << "extension changed" << std::endl;
  else
    std::cout << "something goes wrong...extension not changed"<<std::endl;

  return 0;
}
*/




