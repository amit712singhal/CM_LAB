#include <bits/stdc++.h>
using namespace std;

float dydx(float x, float y)
{
    return ((pow(y, 2) - pow(x, 2)) / (pow(y, 2) + pow(x, 2)));
}

float rungeKutta(float x0, float y0, float x, float h)
{
    int n = (int)((x - x0) / h);

    float k1, k2, k3, k4;

    float y = y0;

    k1 = h * dydx(x0, y);
    k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1);
    k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2);
    k4 = h * dydx(x0 + h, y + k3);

    cout << endl
         << "------------- Runge-Kutta Method -------------" << endl;
    cout << "x0 = " << x0 << ", y0 = " << y << ", h = " << h
         << "\nk1 = " << k1 << "\nk2 = " << k2 << "\nk3 = " << k3 << "\nk4 = " << k4 << endl;

    y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);

    cout << "k = " << y << endl;

    x0 = x0 + h;

    return y;
}

int main()
{
    float x0 = 0, y = 1, x = 0.2, h = 0.2;
    cout << "\nThe value of y at x = " << x << " is : " << rungeKutta(x0, y, x, h);

    return 0;
}
