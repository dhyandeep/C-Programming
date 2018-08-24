#include <iostream>
#include "ExportsFinder.h"
void main(int argc, char *argv[])
{
	if ( argc != 2 ) 
	{
		cout<<"usage: "<< argv[0] <<" <directory>\n";
	}
	else
	{
		ExportsFinder ef;
		ef.Init(argv[1]);
		ef.FindExports();
	}
	
}