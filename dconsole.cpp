#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
double factorial(double n)
{
	double result = n;
	for(int i = n-1; i>0; i--)
	{
		result = result * i;
	}
	return(result);
}
double getNum(int index)
{
	double n1;
	cout << "Number " << index << ": ";
	cin >> n1;
	return(n1);
}
string getInput(string msg)
{
	string userInput;
	cout << msg;
	cin >> userInput;
	return(userInput);
} //end getInput method

void enterContinue()
{
	string temp;
	cout << "\nPress ENTER to continue ";
	cin >> temp;
}

void defaultDisplay()
{
	system("clear");
	cout << "dconsole C++ @ " << system("date") << endl;
	cout << "\n";
} //end defaultDisplay method

int main()
{
	string input;
	string secondaryInput;
	string PAUSE;
	double num1;
	double num2;
	string commands[] = {"add", "sub", "mult", "div", "sqrt", "pow", "factorial"};
	string defaultMsg = "% ";
	defaultDisplay();
	while(true)
	{
		input = getInput(defaultMsg);
		if(input == "exit" || input == "quit" || input == "stop")
		{
			return 0;
		}
		else if(input == "options" || input == "help")
		{
			cout << "All commands:" << endl;
			for(int i = 0; i < sizeof commands / sizeof commands[0]; i++)
			{
				cout << i << ". " << commands[i] << endl;
			}
		}
		else if(input == "add")
		{
			num1 = getNum(1);
			num2 = getNum(2);
			double result = num1 + num2;
			cout << "The sum of " << num1 << " + " << num2 << " is " << result << endl;
		}
		else if(input == "sub")
		{
                        num1 = getNum(1);
                        num2 = getNum(2);
                        double result = num1 - num2;
                        cout << "The difference of " << num1 << " - " << num2 << " is " << result << endl;
		}
		else if(input == "mult")
		{
                        num1 = getNum(1);
                        num2 = getNum(2);
                        double result = num1 * num2;
                        cout << "The product of " << num1 << " * " << num2 << " is " << result << endl;
		}
		else if(input == "div")
		{
                        num1 = getNum(1);
                        num2 = getNum(2);
			if(num2 != 0)
			{
                        	double result = num1 / num2;
				cout << "The quotient of " << num1 << " / " << num2 << " is " << result << endl;
			}
			else
			{
				cout << "You cannot divide by zero." << endl;
			}
		}
		else if(input == "sqrt")
		{
			num1 = getNum(1);
			double result = sqrt(num1);
			cout << "The square root of " << num1 << " is " << result << endl;
		}

		enterContinue();
		defaultDisplay();

	}
} // end main
