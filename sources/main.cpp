#include <iostream>
#include <ReadXmlFile.h>
#include <FileExistenceValidation.h>
#include <UnzipFile.h>
#include <ChangeExt.h>

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

		//se descomprime el .zip					(ok)

		//se lee el archivo content.xml             (ok)

		//motor de extracción de datos				(needed)

		//definición de tipos (strcuts)				(needed)

		//se crea el archivo .TEX					(needed)



		//check the existence of the file before we can continue
		if(!FileExistenceValidation(fileName))
		{	std::cout << "salido en validacion de existencia"<<std::endl;
			return -1;
		}
		//changes the extension of .odf file to .zip file
		if(!ChangeExt(fileName))
		{
			std::cout << "salido en cambio de extension"<<std::endl;
			return -1;
		}
		//perform the ZIP file extraction to .temp/ temporary folder
		if(!UnzipFile(fileName))
		{
			std::cout << "salido en extraccion"<<std::endl;
			return -1;
		}	


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