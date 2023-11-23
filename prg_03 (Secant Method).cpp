// C++ Program to find root of an
// equations using secant method
#include <bits/stdc++.h>
using namespace std;
const double e = 2.718281828;
// function takes value of x and returns f(x)
float f(float x)
{
	// we are taking equation as x^3-2x-5
	float f = pow(x, 3) - 2 * x - 5;
	return f;
}

void secant(float x1, float x2, float E)
{
	float n = 0, xm, x0, c;
	cout << "Iteration |   xm    |  f(xm)" << endl;
	cout << "-------------------------" << endl;
	if (f(x1) * f(x2) < 0)
	{
		do
		{
			// calculate the intermediate value
			x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

			// check if x0 is root of equation or not
			c = f(x1) * f(x0);

			// update the value of interval
			x1 = x2;
			x2 = x0;

			// update number of iteration
			n++;

			// if x0 is the root of equation then break the loop
			if (c == 0)
				break;

			xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

			// Print the iteration, xm, and f(xm)
			cout << "    " << n << "     | " << xm << " | " << f(xm) << endl;

		} while (fabs(xm - x0) >= E); // repeat the loop
									  // until the convergence

		cout << "Root of the given equation = " << x0 << endl;
		cout << "No. of iterations = " << n << endl;
	}
	else
		cout << "Can not find a root in the given interval";
}

// Driver code
int main()
{
	cout << "Function is :: x^3-2x-5" << endl;
	// initializing the values
	float x1 = 2, x2 = 3, E = 0.0001;
	secant(x1, x2, E);
	return 0;
}
