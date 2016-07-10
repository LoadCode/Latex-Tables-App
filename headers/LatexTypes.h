#ifndef _LATEX_TYPES_H_
#define _LATEX_TYPES_H_

namespace lt //Namespace for Latex Types
{
	struct CellStyle
	{
		bool italic;
		bool strong;
		bool center;	
	};

	struct Cell
	{
		std::string content;
		bool hBackgroundColor; //do have background color?
		bool hForegroundColor; //do have foreground color?
	};

	struct Table
	{
		std::string title;
		std::string label;
		std::string caption;
		bool centerInText;	

		int nCells;             //Number of cells in the table
		int nCols;				//Number of nCols in the table
		int nRows;				//Number of nRows in the table
	};

	
} //end namespace

#endif