#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;
bool isIn(double thing, vector<double> area)
{
	bool found = false;
	for(int i = 0; i<area.size(); i++)
	{
		if(thing == area.at(i))
		{
			found = true;
		}
	}
	return(found);
}
double factorial(double n)
{
	double result = n;
	for(int i = n-1; i>0; i--)
	{
		result = result * i;
	}
	return(result);
}
double getNumWithMessage(string msg)
{
	double n1;
	cout << msg;
	cin >> n1;
	return(n1);
}
double getNum(int index)
{
	double n1;
	cout << "Number " << index << ": ";
	cin >> n1;
	return(n1);
}
int getInt(int index)
{
	int n1;
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

double quadraticFormula(string sign, double a, double b, double c)
{
	double positive;
	double negative;
	double b_squared = pow(b, 2);
	double four_a_c = 4 * a * c;
	double radical = b_squared - four_a_c;
	radical = sqrt(radical);
	double denominator = 2 * a;
	positive = (-1 * b) + radical;
	positive = positive / denominator;
	negative = (-1 * b) - radical;
	negative = negative / denominator;
	if(sign == "+" || sign == "positive" || sign == "plus")
	{
		return(positive);
	}
	else
	{
		return(negative);
	}
}
double quadratic(double a, double b, double c)
{
	double negative_b = -1 * b;
	double denominator = 2 * a;
	double b_squared = pow(b, 2);
	double radical = b_squared - (4 * a * c);
	radical = sqrt(radical);
	double numerator1 = (negative_b + radical)/denominator;
	double numberator2 = (negative_b - radical)/denominator;
	return(numerator1);
}
void enterContinue()
{
	cin.ignore();
	cout << "\nPress ENTER to continue ";
	cin.get();
}
int greaterOf(int a, int b)
{
	if(a > b)
	{
		return(a);
	}
	else
	{
		return(b);
	}
}
int lesserOf(int a, int b)
{
	if(a < b)
	{
		return(a);
	}
	else
	{
		return(b);
	}
}
double greaterOf(double a, double b)
{
        if(a < b)
        {
                return(a);
        }
        else
        {
                return(b);
        }
}
double lesserOf(double a, double b)
{
        if(a > b)
        {
                return(a);
        }
        else
        {
                return(b);
        }
}
int gcd(int a, int b)
{
	int gcd;
	for(int i = 1; i<=b; i++)
	{
		if( (a % i == 0) && (b % i == 0))
		{
			gcd = i;
		}
	}
	return(gcd);
}
void defaultDisplay()
{
	system("clear");
	system("python3 graphics.py");
	cout << "dconsole C++ @1.02 " << system("date") << endl;
	cout << "\n";
} //end defaultDisplay method

int main()
{
	string input;
	string secondaryInput;
	string PAUSE;
	double num1;
	double num2;
	int int1;
	int int2;
	string commands[] = {"add", "sub", "mult", "div", "sqrt", "pow", "factorial"};
	string defaultMsg = "% ";
	defaultDisplay();
	while(true)
	{
		vector<double> numbers;
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
		else if(input == "factorial")
		{
			num1 = getNum(1);
			double result = factorial(num1);
			cout << "The factorial of " << num1 << " is " << result << endl;
		}
		else if(input == "quadratic")
		{
			double a = getNumWithMessage("a value: ");
			double b = getNumWithMessage("b value: ");
			double c = getNumWithMessage("c value: ");
			double solution[] = {quadraticFormula("+", a, b, c), quadraticFormula("-", a, b, c)};
			cout << "Result using + : " << solution[0] << endl;
			cout << "Result using - : " << solution[1] << endl;
		}
		else if(input == "factors")
		{
			num1 = getNumWithMessage("Get the factors of what number?: ");
			cout << "Factors of " << num1 << ":" << endl;
			double factor;
			for(double i = 1; i<num1/2; i++)
			{
				factor = num1/i;
				if(int(num1)%int(i) == 0)
				{
					numbers.push_back(factor);
					cout << num1 << " / " << i << " = " << numbers.at(numbers.size()-1) << endl;
				}
			}
		}
		else if(input == "ea" || input == "gcd" || input == "euclidean" || input == "euclideanAlgorithm")
		{
			int1 = getInt(1);
			int2 = getInt(2);
			int gcdResult = gcd(int1, int2);
			cout << "The gcd of " << int1 << " and " << int2 << " is " << gcdResult << endl;
		}
		numbers.clear();
		enterContinue();
		defaultDisplay();

	}
} // end main
