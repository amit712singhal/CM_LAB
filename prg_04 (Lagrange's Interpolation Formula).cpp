#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Data {
public:
    int x, y;
};

double Interpolate(Data f[], int xi, int n) {
    double result = 0;
    for (int i = 0 ; i < n ; i++) {
        double term = f[i].y;
        for (int j = 0 ; j < n ; j++){
            if (j != i) {
                term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
            }
        }
        result += term;
    }
    return result;
}

void Display(Data*);

int main() {
    cout << endl;
    Data f[] = {{1,3}, {2,8}, {3,18}, {4,32}, {5,50}}; // Different set of values
    Display(f);
    cout << "Value of f(6) is : " << Interpolate(f, 6, 5) << endl; // Interpolating for x = 6
    cout << endl;
    return 0;
}

void Display(Data arr[]) {
    cout << "---------------------------------" << endl;
    cout << "|   x     |   f(x)   |" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "|   " << setw(3) << arr[i].x << "   |   " << setw(4) << arr[i].y << "   |" << endl;
    }
    cout << "---------------------------------" << endl;
}
