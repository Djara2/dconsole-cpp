#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string original;
	string comparision;
	cout << "What is the original text?: ";
	getline(cin, original);
	cin.ignore();
	cout << "What is the comparison text?: ";
	getline(cin, comparision);
	cin.ignore();
	string string_cmd = "python similarity.py " + '\"' + original + "\" " + '\"' + comparision + '\"';
	cout << string_cmd << endl; 
	const char *cmd = string_cmd.c_str();
	system(cmd);

	cout << "Hit ENTER to continue " << endl;
}