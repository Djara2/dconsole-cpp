#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	bool WINDOWS = false;
	#ifdef _WIN32
	WINDOWS = true;
	#endif

	if(WINDOWS)
	{
		cout << "Windows" << endl;
	}
	else
	{
		cout << "Linux" << endl;
	}
	string temp;
	getline(cin, temp);
	return 0;	
}
