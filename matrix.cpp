#include <iostream>
using namespace std;
class matrix
{
	public:
		int rowCount;
		int colCount;
		vector<vector<double>> rows;
		string name;
		matrix()
		{
			rowCount = 2;
			colCount = 2;
			rows 
			name = "unnamed matrix";
		}
		matrix(string aname, int r, int c)
		{
			name = aname;
			rowCount = r;
			colCount = c;
				
		}
};
