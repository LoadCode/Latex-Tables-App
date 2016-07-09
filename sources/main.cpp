#include <iostream>
#include <ReadXmlFile.h>
#include <FileExistenceValidation.h>


int main(int nargs, char * args[])
{
	if(nargs < 2)
	{
		std::cout<<"Por favor ingrese un nombre de archivo valido"<<std::endl;
		return 0;
	}
	else
	{
		std::string fileName(args[1]);
		std::string xmlContent;

		//Se vaida la existencia del archvio .odf	(ok)

		//se cambia su extensión a .zip             (ok)

		//se descomprime el .zip					 

		//se lee el archivo content.xml             (ok)

		//motor de extracción de datos

		//se crea el archivo .TEX



		//check the existence of the file before we can continue
		if(FileExistenceValidation(fileName))
			return -1;


		if (ReadXmlFile(fileName,xmlContent))
		{
			std::cout << "El contenido del archivo es\n\n" << std::endl;
			std::cout << xmlContent << std::endl << std::endl;
		}
		else
		{
			std::cout<<"There was a problem with the file, maybe it doesn't exist..."<<std::endl;
			return -1;
		}
	}
	return 0;
}