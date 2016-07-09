#ifndef _CHANGE_EXTENSION_H_
#define _CHANGE_EXTENSION_H_

/*This function uses the <cmd> command on linux to change de the extension     */
/*of the *.<oldExt> and sets *.<newExt> extension to the file. 				   */
/*By deafult, this function tries to change the extension of a filename with   */
/*.odf extension and leave it as a .zip file 								   */
/*Returns true if command executes succssefully, false in other case.		   */
/*Note: <cmd> must finish with white-space for concatenation purpouses         */

bool ChangeExt(std::string fileName, std::string cmd = std::string("mv "),\
std::string oldExt = std::string(".odf"), std::string newExt = std::string(".zip"));

#endif