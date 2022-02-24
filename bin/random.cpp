#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
		string input;
		string output;
		string free_string;
		int int1;
		int int2;
		string string_cmd;
		while(true)
		{
			system("python3 bin/graphics.py md \"# Random Toolkit \"");
			system("python3 bin/graphics.py normal \"[green]m[/] - options\"");
			cout << "\n> ";
			cin >> input;
			if(input == "m" || input == "options")
			{
				cout << "1. Random number in range\n2. Random \"word\"\n\nChoice?: ";
				cin >> input;
				if(input == "1")
				{
					input = "randint";
				}
				else if(input == "2")
				{
					input = "randword";
				}
			}
			if(input == "exit" || input == "quit" || input == "stop" || input == "ex")
			{
				return 0;
			}
			if(input == "randint")
			{
				cout << "Lower bound?: ";
				cin >> int1;
				cout << "\nUpper bound?: ";
				cin >> int2;
				string_cmd = "python3 bin/drandom.py randint " + to_string(int1) + " " + to_string(int2);
				const char *cmd = string_cmd.c_str();
				system(cmd);
			}
			else if(input == "randword")
			{
				cout << "Lower bound?: ";
				cin >> int1;
				cout << "\nUpper bound?: ";
				cin >> int2;
				string_cmd = "python3 bin/drandom.py randword " + to_string(int1) + " " + to_string(int2);
				const char *cmd = string_cmd.c_str();
				system(cmd);
			}
			else
			{
				system("python3 bin/error.py \"command not implemented.\"");
			}
			cin.ignore();
			cout << "\nHit ENTER to continue... ";
			cin.get();
			system("python3 bin/clear.py");
		}


}