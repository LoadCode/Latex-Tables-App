#include <iostream>
#include <fileHandler.h>



int main(int nargs, char * args[])
{
	if(nargs < 2)
	{
		std::cout<<"Por favor ingrese un nombre de archivo valido"<<std::endl;
		return 0;
	}
	else
	{
		std::cout << args[1]<<std::endl;
		std::string fileName(args[1]);
		std::string xmlContent;

		if (ReadXmlFile(fileName,xmlContent))
		{
			std::cout << "El contenido del archivo es\n\n"<<std::endl;
			std::cout << xmlContent << std::endl<< std::endl;
		}
		else
		{
			std::cout<<"hubo problemas"<<std::endl;
		}
	}
	return 0;
}