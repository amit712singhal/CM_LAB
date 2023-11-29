#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double dydx(double x, double y)
{
	return (pow(x, 2) + pow(y, 2));
}

double RungeKutta(double x0, double y0, double x, double h)
{
	int n = (int)((x - x0) / h);
	double k1, k2, k3, k4, k, y = y0;

	cout << left << setw(15) << "Iterations"
		 << "|"
		 << setw(15) << "x"
		 << "|"
		 << setw(15) << "k1"
		 << "|"
		 << setw(15) << "k2"
		 << "|"
		 << setw(15) << "k3"
		 << "|"
		 << setw(15) << "k4"
		 << "|"
		 << setw(15) << "k"
		 << "|"
		 << setw(15) << "y"
		 << "|" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 1; i <= n; i++)
	{
		k1 = h * dydx(x0, y);
		k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1);
		k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2);
		k4 = h * dydx(x0 + h, y + k3);
		k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		y = y + k;

		cout << left << setw(15) << i << "|"
			 << setw(15) << x0 << "|"
			 << setw(15) << k1 << "|"
			 << setw(15) << k2 << "|"
			 << setw(15) << k3 << "|"
			 << setw(15) << k4 << "|"
			 << setw(15) << k << "|"
			 << setw(15) << y << "|" << endl;

		x0 = x0 + h;
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
	return y;
}

int main()
{
	cout << endl;
	double x0 = 0, y0 = 1, x = 0.2, h = 0.1;
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\tTable of Runge-Kutta Method" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;

	double ans = RungeKutta(x0, y0, x, h);
	cout << endl;
	cout << "The value of y at x = " << x << " is -> " << ans << endl;
	return 0;
}
