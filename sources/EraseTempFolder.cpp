#include <cstdlib>

void EraseTempFolder()
{
	system("rm -r .temp/");
}