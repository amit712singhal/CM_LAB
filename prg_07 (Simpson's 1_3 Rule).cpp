#include <iostream>
#include <iomanip> // for setw
#include <cmath>
using namespace std;

// Function to calculate f(x)
float func(float x)
{
    return log(x);
}

// Function for approximate integral
float simpsons_1_3(float ll, float ul, int n)
{
    // Calculating the value of h
    float h = (ul - ll) / n;

    // Array for storing value of x and f(x)
    float x[10], fx[10];

    // Calculating values of x and f(x)
    for (int i = 0; i <= n; i++)
    {
        x[i] = ll + i * h;
        fx[i] = func(x[i]);
    }

    // Print the table header
    cout << setw(8) << "|"
         << setw(8) << "x" << setw(8) << "|" << setw(15) << "log(x)"
         << "        |" << endl
         << "       -----------------------------------------" << endl;

    // Print the values of x and f(x)
    for (int i = 0; i <= n; i++)
    {
        cout << setw(8) << "|" << setw(8) << x[i] << setw(8) << "|" << setw(15) << fx[i] << "        |" << endl;
    }

    // Calculating result
    float res = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == n)
            res += fx[i];
        else if (i % 2 != 0)
            res += 4 * fx[i];
        else
            res += 2 * fx[i];
    }
    res = res * (h / 3);

    return res;
}

// Driver program
int main()
{
    int n;
    float lower_limit, upper_limit;

    // Get user input for lower limit, upper limit, and number of intervals
    cout << endl
         << "Enter lower limit: ";
    cin >> lower_limit;
    cout << "Enter upper limit: ";
    cin >> upper_limit;
    cout << "Enter number of intervals (n): ";
    cin >> n;

    // Calculate and print the result
    cout << "Result: " << simpsons_1_3(lower_limit, upper_limit, n) << endl;

    return 0;
}
