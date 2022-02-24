#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	string OS;
	#ifdef _WIN32
		OS = "windows";
	#endif
	#ifdef __linux__
		OS = "linux";
	#endif
	if(OS == "linux")
	{
		system("python3 bin/eztex.py");	
	}
	else
	{
		system("python3 bin\\eztex.py");
	}
	
}
