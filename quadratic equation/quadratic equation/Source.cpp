#include<iostream> 
#include<cmath> 
#include<iomanip> 
using namespace std;

int main()
{
    long double p, q;
    cin >> p >> q;

    long double delta = p * p - 4 * q;
    long double x1, x2;

    cout << setprecision(30) << fixed;

    cout << "Metoda klasyczna: \n";
    cout << "x1: " << (-p - sqrtl(delta)) / 2 << '\n';
    cout << "x2: " << (-p + sqrtl(delta)) / 2 << '\n';

    if (p < 0) {
        x1 = (-p - sqrtl(delta)) / 2;
        x2 = q / x1;
    }
    else {
        x2 = (-p + sqrtl(delta)) / 2;
        x1 = q / x2;
    }

    cout << "Metoda numeryczna:\n";
    cout << "x1: " << x1 << '\n';
    cout << "x2: " << x2 << '\n';

    return 0;
}