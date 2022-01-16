#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
void wincopy(string text)
{
        fstream myFile;
        myFile.open("tempCopy.txt", ios::out);
        if(myFile.is_open())
        {
                myFile << text;
                myFile.close();
        }
        system("clip < tempCopy.txt");
        system("del tempCopy.txt");
}
int main()
{
	string userin;
	cout << "File name?: ";
	getline(cin, userin);
	for(int i=0; i<userin.length(); i++)
	{
		if(userin[i] == ' ')
		{
			userin[i] = '_';
		}
	}
	wincopy(userin);
}
