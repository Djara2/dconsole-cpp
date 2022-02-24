#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
	string OS;
	string freeString;
	#ifdef _WIN32
		OS = "windows";
	#endif

	#ifdef __linux__
		OS = "linux";
	#endif
	string input;
	string string_cmd;
	while(true)
	{
		if(OS == "windows")
		{
			system("cls");
		}
		else
		{
			system("clear");
		}
		cout << "AUTO COMPILER v0.01\n\n";
		if(OS == "windows")
		{
			system("dir");
		}
		else if(OS == "linux")
		{
			system("ls -d *cpp");
		}
		cout << "\nFile to compile?: ";
		cin >> input;
		if(input == "exit")
		{
			return 0;
		}
		else
		{
			freeString = "g++ " + input + ".cpp -o " + input;
			if(OS == "windows")
			{
				freeString += ".exe";
			}
			const char *cmd = freeString.c_str();
			system(cmd);
		}
		cin.ignore();
		cout << "\nPress ENTER to continue ";
		cin.get();
	}
}