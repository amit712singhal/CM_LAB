#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int i, j, n;
    float A[40][40], x[40], z[40], e[40], zmax, emax;

    cout << "\nEnter the order of matrix:";
    cin >> n;

    cout << "\nEnter matrix elements row-wise\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "A[" << i << "][" << j << "]=";
            cin >> A[i][j];
        }
    }

    cout << "\nEnter the column vector\n";
    for (i = 1; i <= n; i++)
    {
        cout << "X[" << i << "]=";
        cin >> x[i];
    }

    do
    {
        for (i = 1; i <= n; i++)
        {
            z[i] = 0;
            for (j = 1; j <= n; j++)
            {
                z[i] = z[i] + A[i][j] * x[j];
            }
        }

        zmax = fabs(z[1]);
        for (i = 2; i <= n; i++)
        {
            if ((fabs(z[i])) > zmax)
                zmax = fabs(z[i]);
        }

        for (i = 1; i <= n; i++)
        {
            z[i] = z[i] / zmax;
        }

        for (i = 1; i <= n; i++)
        {
            e[i] = 0;
            e[i] = fabs((fabs(z[i])) - (fabs(x[i])));
        }

        emax = e[1];
        for (i = 2; i <= n; i++)
        {
            if (e[i] > emax)
                emax = e[i];
        }

        for (i = 1; i <= n; i++)
        {
            x[i] = z[i];
        }

    } while (emax > 0.001);

    cout << "\nThe required eigen value is " << zmax << endl;
    cout << "\nThe required eigen vector is :\n";
    for (i = 1; i <= n; i++)
    {
        cout << "[" << z[i] << "]\n";
    }

    return 0;
}
