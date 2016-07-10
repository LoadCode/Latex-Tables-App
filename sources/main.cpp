#include <iostream>
#include <vector>
#include <ReadXmlFile.h>
#include <FileExistenceValidation.h>
#include <UnzipFile.h>
#include <ChangeExt.h>
#include <LatexTypes.h>
#include <TableNumberRows.h>
#include <TableNumberCols.h>


int main(int nargs, char * args[])
{
	if(nargs < 2)
	{
		std::cout<<"Por favor ingrese un nombre de archivo valido"<<std::endl;
		return 0;
	}
	else
	{
		std::string FullPathXmlFile(".temp/content.xml");
		std::string fileName(args[1]);
		std::string zipFileName(args[1]);
		std::string xmlContent;
		int nCols;						  //The number of columns detected in the .odf file
		int nRows;						  //The number of rows detected in the .odf file
		lt::Table table;                  //The table struct
		std::vector<lt::Cell> cellVec;        //Vector of cell structures
		std::vector<lt::CellStyle> styleVec;  //Vector of style structures
		std::cout<<"archivo: "<<fileName<<std::endl;

		//Se vaida la existencia del archvio .odf	  (ok)

		//se cambia su extensión a .zip               (ok)

		//se descomprime el .zip					  (ok)

		//se lee el archivo content.xml               (ok)

		//definición de tipos (structures)			  (ok)

		//obtener cantidad de columnas				  (ok)

		//obtener cantidad de filas 				  (ok)

		//devolver archivo original a extension .ods  (ok)

		//funcion que borre la carpeta temporal		  (needed)

		//obtener el contenido de las celdas          (needed)

		//obtener la cantidad de estilos del archivo  (needed)

		//obtener los estilos                         (needed)

		//se crea el archivo .TEX					  (needed)



		//check the existence of the file before we can continue
		if(!FileExistenceValidation(fileName))
		{ std::cout << "validacion de exitencia falla"<<std::endl;
			return -1;
		}

		//changes the extension of .odf file to .zip file
		if(!ChangeExt(fileName))
		{
			std::cout << "cambio de extension falla"<<std::endl;
			return -1;
		}

		zipFileName.replace(zipFileName.find(".ods"),std::string(".zip").size(),".zip");
		//perform the ZIP file extraction to .temp/ temporary folder
		if(!UnzipFile(zipFileName)) 
		{
			std::cout<<"fallo al descomprimir el archivo"<<std::endl;
			return -1;
		}	

		//gets back the original file extension from .zip to .ods
		if(!ChangeExt(zipFileName,std::string("mv "),std::string(".zip"),std::string(".ods")))
		{
			std::cout << "cambio de extension .zip a .ods falla"<<std::endl;
			return -1;
		}

		//creating the full path to the new <content.xml> file in hidden subfolder .temp/
		FullPathXmlFile = fileName.substr(0,(fileName.find_last_of("/")+1)) + FullPathXmlFile;
		std::cout << "El nuevo path es: "<<FullPathXmlFile<<std::endl;

		//If true, from here all the work is done based on the xmlContent string (other files not needed)
		if (ReadXmlFile(FullPathXmlFile,xmlContent))
		{
			nCols = TableNumberCols(xmlContent);
			nRows = TableNumberRows(xmlContent);
			std::cout<<"Ncols = "<<nCols<<std::endl;
			std::cout<<"Mrows = "<<nRows<<std::endl;
		}	
		else
		{
			std::cout<<"fallo con el path: "<<FullPathXmlFile<<std::endl;	
			return -1;
		}
	}
	return 0;
}