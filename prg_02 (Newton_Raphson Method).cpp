#include <iostream>
#include <math.h>

using namespace std;

double f(double x) // function is xlog10x = 1.2
{
    return x * log10(x) - 1.2;
}

double g(double x) // derivative of function is log10x + .43429
{
    return log10(x) + 0.43429;
}

void newton_Raphson(double x, double e)
{
    double h = f(x) / g(x);
    int iterations = 0;
    cout << "Iteration\t x\t\t f(x)" << endl;
    while (abs(h) >= e)
    {
        h = f(x) / g(x);
        x = x - h;
        iterations++;
        cout << iterations << "\t\t " << x << "\t\t " << f(x) << endl;
    }
    cout << "The value of the root is: " << x << endl;
    cout << "Number of iterations: " << iterations << endl;
}

int main()
{
    double x[50];
    static double p = 0.0;
    for (int i = 0; i < 50; i++)
    {
        x[i] = f(p);
        p++;
    }
    for (int i = 0; i < 50; i++)
    {
        if ((x[i] < 0 && x[i + 1] > 0) || (x[i] > 0 && x[i + 1] < 0))
        {
            cout << "Possible root is between: " << i << " & " << i + 1 << endl;
            break;
        }
        else
            continue;
    }
    double x0, error;
    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter allowed error: ";
    cin >> error;
    newton_Raphson(x0, error);
    return 0;
}