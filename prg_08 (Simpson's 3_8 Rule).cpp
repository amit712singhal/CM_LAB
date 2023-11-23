#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Given function to be integrated
float func(float x)
{
    return exp(x);
}

// Function to perform calculations and display table
void calculateANDdisplay(float lower_limit, float upper_limit,
                         int interval_limit)
{
    float interval_size = (upper_limit - lower_limit) / interval_limit;

    // Print the table header
    cout << setw(8) << "|"
         << setw(10) << "x" << setw(8) << "|" << setw(15) << "e^x"
         << "        |" << endl
         << "       -------------------------------------------" << endl;

    // Calculate values and display table
    for (int i = 0; i <= interval_limit; i++)
    {
        float x = lower_limit + i * interval_size;
        float fx = func(x);
        cout << setw(8) << "|" << setw(10) << x << setw(8) << "|" << setw(15) << fx << "        |" << endl;
    }

    // Calculate integral using Simpson's 3/8 rule
    float sum = func(lower_limit) + func(upper_limit);

    for (int i = 1; i < interval_limit; i++)
    {
        if (i % 3 == 0)
            sum = sum + 2 * func(lower_limit + i * interval_size);
        else
            sum = sum + 3 * func(lower_limit + i * interval_size);
    }

    float integral_res = (3 * interval_size / 8) * sum;

    // Display the result
    cout << "Integral Result: " << integral_res << endl;
}

// Driver Code
int main()
{
    float lower_limit, upper_limit;
    int interval_limit;

    // Get user input for lower limit, upper limit, and interval size
    cout << endl
         << "Enter lower limit: ";
    cin >> lower_limit;
    cout << "Enter upper limit: ";
    cin >> upper_limit;
    cout << "Enter number of intervals: ";
    cin >> interval_limit;

    // Display table and integral result
    calculateANDdisplay(lower_limit, upper_limit, interval_limit);

    return 0;
}
 