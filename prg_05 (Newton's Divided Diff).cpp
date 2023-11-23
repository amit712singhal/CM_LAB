#include <iostream>
using namespace std;

int main()
{
	// Declaration of variables
	int n;

	// User input for total number of data points
	cout << endl
		 << "Enter total number of data :: ";
	cin >> n;

	// Arrays to store x and y values
	float x[n], y[n];

	// User input for x and f(x) values
	cout << endl
		 << "----------- Enter values of x & f(x)-------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "  x[" << i + 1 << "]  = ";
		cin >> x[i];
		cout << "f(x[" << i + 1 << "]) = ";
		cin >> y[i];
	}

	// Displaying entered x and f(x) values in a table
	cout << endl
		 << "  x  | ";
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << "   | ";
	}

	cout << endl
		 << "f(x) | ";
	for (int i = 0; i < n; i++)
	{
		cout << y[i] << " | ";
	}

	float xp, yp = 0;

	// User input for the value of x to calculate f(x)
	cout << endl
		 << endl
		 << "Enter the value of x for which f(x) has to be calculated  ::: ";
	cin >> xp;

	// Lagrange interpolation algorithm
	for (int i = 0; i < n; i++)
	{
		float p = 1;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				p *= (xp - x[j]) / (x[i] - x[j]);
			}
		}
		yp += p * y[i];
	}

	// Displaying the calculated value of f(x)
	cout << endl;
	cout << "Value of f(" << xp << ") is -> " << yp << endl;

	return 0;
}
