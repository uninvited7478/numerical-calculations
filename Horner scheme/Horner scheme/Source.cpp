#include <bits/stdc++.h> 
using namespace std;

double horner(int deg, vector<double>& a, double x)
{
    vector<double> b(deg + 1);
    b[0] = a[0];
    for (int i = 1; i <= deg; ++i)
    {
        b[i] = b[i - 1] * x + a[i];
    }
    return b[deg];
}

double horner_rec(int deg, vector<double>& a, double x)
{
    if (deg == 0) return a[0];
    return horner_rec(deg - 1, a, x) * x + a[deg];
}

int main()
{
    int deg;
    cout << "Deg: \n";
    cin >> deg;

    vector<double> a(deg + 1);
    cout << "A: \n";
    for (int i = 0; i <= deg; ++i) {
        cin >> a[i];
    }

    double x;
    cout << "X: \n";
    cin >> x;

    cout << "Horner iter: " << horner(deg, a, x) << '\n';
    cout << "Horner rec: " << horner_rec(deg, a, x) << '\n';

    return 0;
}