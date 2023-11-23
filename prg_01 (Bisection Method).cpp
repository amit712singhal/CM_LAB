// C++ program for implementation of Bisection Method for solving equations
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;

const double e = 2.718281828;

// An example function whose solution is determined using Bisection Method. The function is x*e^x - 1
double func(double x)
{
	return x * x * x - 2 * x - 5;
}

// Prints root of func(x) with error
void bisection(double a, double b, double error)
{

	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		return;
	}
	else
	{
		double c = 0.0;
		int i = 1;

		while ((b - a) >= error)
		{
			// Find middle point
			c = (a + b) / 2;

			cout << "x(" << i++ << ") = " << c << endl;

			// Check if middle point is root
			if (func(c) == 0.0)
				break;

			// Decide the side to repeat the steps
			else if (func(c) * func(a) < 0)
			{
				b = c;
			}
			else
			{
				a = c;
			}
		}
		cout << "\nThe value of root is : " << c << endl;
	}
}

// Driver program to test above function
int main()
{
	// Initial values assumed
	double a, b, er;
	cout << "\nThe function is: xe^x-1" << endl;
	cout << "\nEnter Values of (a,b) :- ";
	cin >> a >> b;
	cout << "Enter Allowed Error (correct upto x decimal places):: ";
	cin >> er;

	cout << "Value of Fucntion at a=0 is :- " << func(a) << endl
		 << "Value of Fucntion at b=1 is :- " << func(b) << endl;
	cout << "\nThe Approximations are ->" << endl;
	bisection(a, b, er);
	return 0;
}