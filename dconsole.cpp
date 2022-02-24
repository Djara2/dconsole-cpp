#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
//SYSTEM = 1 = WINDOWS --- = 2 = LINUX WSL --- = 3 = LINUX NATIVE
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
void wslcopy(string text)
{
        fstream myFile;
        myFile.open("tempCopy.txt", ios::out);
        if(myFile.is_open())
        {
                myFile << text;
                myFile.close();
        }
        system("cat tempCopy.txt | clip.exe");
        system("rm tempCopy.txt");
}
void copy(string text, int systemType)
{
	if(systemType == 1)
	{
		wincopy(text);
	}
	else if(systemType == 2)
	{
		wslcopy(text);
	}
	else
	{
		fstream myFile;
        	myFile.open("tempCopy.txt", ios::out);
        	if(myFile.is_open())
        	{
                	myFile << text;
                	myFile.close();
        	}
        	system("xclip -sel c < tempCopy.txt"); //copying on linux will require xclip --- sudo install xclip
        	system("rm tempCopy.txt");
	}

}
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
int getIntWithMessage(string msg)
{
	int n1;
        cout << msg;
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
int ezMenu(vector<string> options)
{
	int selection;
	for(int i=0; i<options.size(); i++)
	{
		cout << i+1 << ". " << options.at(i) << endl;
	}
	cout << "\nChoice?: ";
	cin >> selection;
	cout << "\n";
	return(selection);
}
void defaultDisplay(int systemType)
{
	if(systemType == 1)
	{
		system("cls");
	}
	else
	{
		system("clear");
	}
	system("python3 graphics2.py md \"# dconsole c++\"");
	system("python3 graphics2.py normal \"[yellow]dconsole C++ @v1.04[/]\t[cyan]m[/] - menu\t[cyan]!filename[/] - run an applet\"");
	//cout << "dconsole C++ @1.03 " << endl;
	cout << "\n";
} //end defaultDisplay method

int main()
{
	string input;
	string secondaryInput;
	vector<string> options;
        vector<double> numbers;
	vector<string> building;
	vector<string> freeVector;
	vector<string> freeVector2;
	string freeString;
	string freeString2;
	double a;
	const double PI = 3.14159;
	double b;
	double c;
	double d;
	double m;
	double num1;
	double num2;
	double num3;
	double num4;
	int int1;
	int int2;
	int int3;
	int int4;
	double lowerBound;
	double upperBound;
	const char *COMMAND;
	int systemType; //1 = windows 2 = WSL 3 = native linux
	systemType = 2;
	#ifdef _WIN32
	systemType = 1;
	#endif
	vector<string> commands = {"add", "sub", "mult", "div", "sqrt", "pow", "factorial", "gcd", "qaudraticFormula", "factors", "html", "function", "None", "Quit"};
	string defaultMsg = "% ";
	//cout << "What system are you using?\n\n1. Windows\n2. Linux (WSL)\n3. Linux (Native)\n\n% ";
	//cin >> systemType;
	cout << systemType << endl;
	defaultDisplay(systemType);
	while(true)
	{
		input = getInput(defaultMsg);
		if(input == "ezmenu" || input == "m")
		{
			int1 = ezMenu(commands);
			input = commands.at(int1-1);
			cout << "\n";
		}
		if(input == "exit" || input == "quit" || input == "stop" || input == "Quit")
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
			int1 = round(num1);
			int2 = round(num2);
			if(num2 != 0)
			{
                        	double result = num1 / num2;
				cout << "The quotient of " << num1 << " / " << num2 << " is " << result << endl;
				cout << endl;
				cout << "INTEGER DIVISION\n" << endl;
				int3 = int1 / int2;
				int4 = int1 % int2;
				cout << "For x = dq + r:\n\n" << int1 << " = " << int2 << "(" << int3 << ") + " << int4 << "\n" << endl;
				int1 = int2 * int3;
				cout << "\t" << int2 << "(" << int3 << ") = " << int1 << "\n" << endl;
			}
			else
			{
				cout << "You cannot divide by zero." << endl;
			}

		}
		else if(input[0] == '!')
		{
			//system("cd bin");
			if(systemType == 1)
			{
				system("cls");
				//system("cd bin");
				freeString = "\"bin\\" + input.substr(1, input.length()) + ".exe\"";
				cin.get();
				COMMAND = freeString.c_str();
				system(COMMAND);
			}
			else
			{
				system("clear");
				freeString = "./bin/" + input.substr(1, input.length()-1);
				COMMAND = freeString.c_str();
				system(COMMAND);
			}
		}
		else if(input == "sequence" || input == "seq")
		{
			SEQUENCE: cout << "What are you making?:\n\n1. Markdown List\
					  \n2. Tuple (Markdown)\n3.Tuple (HTML)\n4. Abort process\n" << endl;
			try
			{	
				
				SEQUENCE_SELECTION:int1 = getIntWithMessage("Selection?: ");
				if(int1 == 1)
				{
					cout << "\nOrdering scheme?: \n\n1. Bulleted\n2. Numeric\n3. Alphabetical\n4. Go up one level\n5. Abort process\n" << endl;
					MD_ORDERING_SELECTION: try{
						cout << endl;
						int2 = getIntWithMessage("Selection?: ");
						if(int2 == 4)
						{
							cout << endl;
							goto SEQUENCE;
						}

					}
					catch(...)
					{
						cout << "ERROR: input must be a string corresponding to the provided options in the list.";
						enterContinue();
						goto MD_ORDERING_SELECTION;
					}
				}

				else if(int1 == 2)
				{
					cout << "Unimplemented." << endl;
				}
				
				else if(int1 == 4)
				{
					cout << "\nMaybe another time.\n" << endl;
				}
				
				else
				{
					cout << "ERROR: input is out of bounds for list options.\n" << endl;
					enterContinue();
					goto SEQUENCE_SELECTION;
				}

			}
			catch(...)
			{
				cout << "ERROR: please enter a numeric value corresponding to one of the list items as input.\n" << endl;
				enterContinue();
				goto SEQUENCE;
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
		else if(input == "mod")
		{
			int1 = getIntWithMessage("Dividend?: ");
			int2 = getIntWithMessage("Divisor?: ");
			int3 = int1 % int2;
			cout << "Result of " << int1 << " % " << int2 << " ---> " << int3 << endl;
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
			auto start = high_resolution_clock::now();
			int gcdResult = gcd(int1, int2);
			cout << "The gcd of " << int1 << " and " << int2 << " is " << gcdResult << endl;
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Completed in " << duration.count() << " microseconds" << endl;
		}
		else if(input == "test")
		{
			wincopy("success");
		}
		else if(input == "sys" || input == "system")
		{
			if(systemType == 1)
			{
				cout << "Your system is WINDOWS" << endl;
			}
			else
			{
				cout << "Your system is LINUX" << endl;
			}
		}
		else if(input == "function" || input == "fx")
		{
			int functionType;
			cout << "What type of function is this?" << endl;
			cout << "1. linear\n2. quadratic\n3. cubic\n4. log\n5. ln\n6. sin\n7. cos\n8. tan\n" << endl;
			cout << "Choice?: ";
			cin >> functionType;
			switch(functionType)
			{
				case 1:
					m = getNumWithMessage("Value for m (slope)?: ");
					b = getNumWithMessage("Value for b (y-intercept)?: ");
					lowerBound = getNumWithMessage("Lower bound?: ");
					upperBound = getNumWithMessage("Upper bound?: ");
					cout << "y = " << m << "x + " << b << "\n" << endl;
					for(int i = lowerBound; i<=upperBound; i++)
					{
						cout << "@ x = " << i << " | " << ((m*i) + b) << endl;
					}
					break;
				case 2:
					a = getNumWithMessage("Value for a: ");
					b = getNumWithMessage("Value for b: ");
					c = getNumWithMessage("Value for c: ");
					lowerBound = getNumWithMessage("Lower bound?: ");
					upperBound = getNumWithMessage("Upper bound?: ");
					cout << "y = " << a << "(x^2) + " << b << "x + " << c << endl;
					for(int i = lowerBound; i<=upperBound; i++)
					{

                                                cout << "@ x = " << i << " | " << ((a * pow(i, 2)) + (b * i) + c) << endl;
					}
					break;
				case 3:
                                        a = getNumWithMessage("Value for a: ");
                                        b = getNumWithMessage("Value for b: ");
                                        c = getNumWithMessage("Value for c: ");
					d = getNumWithMessage("Value for d: ");
                                        lowerBound = getNumWithMessage("Lower bound?: ");
                                        upperBound = getNumWithMessage("Upper bound?: ");
                                        for(int i = lowerBound; i<=upperBound; i++)
                                        {

                                                cout << "@ x = " << i << " | " << ((a * pow(i, 3)) + (b * pow(i, 2)) + (c * i) + d) << endl;
                                        }	
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:	
					//sin function is in radians for C++ built in
					cout << "Units?:" << endl;
					cout << "1. Degrees\n2. Radians\n\nChoice?: " << endl;
					cin >> int1;
					cout << "Parameter?: ";
					cin >> num1;
					if(int1 == 1)
					{
						num1 = num1 * PI;
						num1 = num1/180;
						freeString = "deg";
					}
					else
					{
						freeString = "rad";
					}
					num2 = sin(num1);
					cout << "The result of sin(" << num1 << " " << freeString << ") is " << num2 << endl; 
					break;
			}
		}
		else if(input == "html")
		{
			cout << "What HTML related thing do you want to do?" << endl;
			options.push_back("Create a table");
			options.push_back("Add a color span tag");
			options.push_back("Highlight span tag");
			for(int i = 0; i<options.size(); i++)
			{
				cout << i+1 << ". " << options.at(i) << endl;
			}
			int3 = getIntWithMessage("Choice?: ");
			switch(int3)
			{
				case 1:
					cin.ignore();
					cout << "Title of table?: ";
					getline(cin, freeString);
					building.push_back(freeString);
					cin.ignore();
					cout << "Number of rows?: ";
					cin >> int1;
					cin.ignore();
					cout << "Number of columns?: ";
					cin >> int2;
					for(int c = 0; c<int2; c++) //give names to the column headers
					{
						cin.ignore();
						cout << "Column header for column # " << c+1 << "?: ";
						getline(cin, freeString);
						freeVector.push_back(freeString);
					}
					for(int i = 0; i<int1; i++) //populate rows
					{
						cout << "Row " << i+1 << ":" << endl;
						for(int j = 0; j<int2; j++) //populate columns
						{
							cin.ignore();
							cout << "Details for R: " << i+1 << "@ C: " << j+1 << " (\"" << freeVector.at(j) << "\")?: ";
							getline(cin, freeString);
							freeVector2.push_back(freeString);
						}
					}
					freeString = "<table>\n\t<thead>\n\t\t<tr>\n\t\t\t<th colspan=\"" + to_string(int2) + "\">" + building.at(0) + "</th>\n\t\t</tr>\n\t</thead>\n\t<tbody>";
					for(int h = 0; h < freeVector.size(); h++)
					{
						freeString = freeString + "\n\t\t<th>" + freeVector.at(h) + "</th>";
					}
					int4 = 0;
					for(int r = 0; r<int1; r++)
					{
						freeString = freeString + "\n\t\t<tr>";
						for(int c = 0; c<int2; c++)
						{
							freeString = freeString + "\n\t\t\t<td>" + freeVector2.at(int4) + "</td>";
							int4++;
						}
					}
					freeString = freeString + "\n\t\t</tr>\n\t</tbody>\n</table>";
					cout << "\nCreated table: \n\n" << freeString << "\n\nCopy result? [Y/N]: ";
					cin >> secondaryInput;
				       	if(secondaryInput == "y" || secondaryInput == "yes" || secondaryInput == "Y" || secondaryInput == "Yes" || secondaryInput == "YES")
					{
						copy(freeString, systemType);
					}
					break;
				case 2:
					freeVector.clear();
					freeVector2.clear();
					freeVector.push_back("green");
					freeVector.push_back("red");
					freeVector.push_back("orange");
					freeVector.push_back("yellow");
					freeVector.push_back("pink");
					freeVector.push_back("grey");
					freeVector.push_back("cyan");
					freeVector2.push_back("#8eb398");
					freeVector2.push_back("#cd3333");
					freeVector2.push_back("#ff7f24");
					freeVector2.push_back("#e4c514");
					freeVector2.push_back("#ef9ed2");
					freeVector2.push_back("#858693");
					freeVector2.push_back(" #51ADD5");
					for(int i=0; i<freeVector.size(); i++)
					{
						cout << i+1 << ". " << freeVector.at(i) << endl;
					}
					cout << "\n" << endl;
					cout << "Which color?: ";
					cin >> int1;
					cin.ignore();
					cout << "Colorize what text?: ";
					getline(cin, freeString);
					freeString2 = "<span style = \"color: " + freeVector2.at(int1-1) + "\">" + freeString + "</span>";
					cout << "Result: " << freeString2 << "\n" << endl;
					cout << "Copy result?: ";
					cin >> freeString;
					if(freeString == "y" || freeString == "Y" || freeString == "yes" || freeString == "Yes" || freeString == "YES")
					{
						copy(freeString2, systemType);
                                        }     
					break;
				case 3:
					freeVector.clear();
                                        freeVector2.clear();
                                        freeVector.push_back("green");
                                        freeVector.push_back("red");
                                        freeVector.push_back("orange");
                                        freeVector.push_back("yellow");
					freeVector.push_back("pink");
                                        freeVector2.push_back("#8eb398");
                                        freeVector2.push_back("#cd3333");
                                        freeVector2.push_back("#ff7f24");
                                        freeVector2.push_back("#e4c514");
					freeVector2.push_back("#ef9ed2");
                                        for(int i=0; i<freeVector.size(); i++)
                                        {
                                                cout << i+1 << ". " << freeVector.at(i) << endl;
                                        }
                                        cout << "\n" << endl;
                                        cout << "Which color?: ";
                                        cin >> int1;
                                        cin.ignore();
                                        cout << "Colorize what text?: ";
                                        getline(cin, freeString);
                                        freeString2 = "<span style = \"background-color: " + freeVector2.at(int1-1) + "\">" + freeString + "</span>";
                                        cout << "Result: " << freeString2 << "\n" << endl;
                                        cout << "Copy result?: ";
                                        cin >> freeString;
                                        if(freeString == "y" || freeString == "Y" || freeString == "yes" || freeString == "Yes" || freeString == "YES")
                                        {
                                        	copy(freeString2, systemType);
                                        }	
					break;
				default:
					cout << "Unrecognized selection." << endl;
			}	
		}	
		numbers.clear();
		options.clear();
		freeVector.clear();
		freeVector2.clear();
		building.clear();
		enterContinue();
		defaultDisplay(systemType);

	}
} // end main
