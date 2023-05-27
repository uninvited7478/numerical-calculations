#include <bits/stdc++.h> 
using namespace std;

const double eps = 0.0000001;

double horner(int deg, double x, vector<double>& a)
{
    vector<double> b(deg + 1);
    b[0] = a[0];
    for (int i = 1; i <= deg; ++i)
    {
        b[i] = b[i - 1] * x + a[i];
    }
    return b[deg];
}

double zero_of_a_func(int deg, vector<double>& a, double p_left, double p_right)
{
    double x1;
    double f_left = horner(deg, p_left, a);
    while (fabs(p_left - p_right) > eps)
    {
        x1 = (p_left + p_right) / 2;
        double f1 = horner(deg, x1, a);
        if (fabs(f1) < eps) {
            return x1;
        }
        if (f_left * f1 < 0) {
            p_right = x1;
        }
        else {
            p_left = x1;
        }
    }
    return x1;
}

int main()
{
    int deg;
    cout << "Deg: \n";
    cin >> deg;

    vector<double> a(deg + 1);
    cout << "A: \n";
    for (int i = 0; i <= deg; ++i)
    {
        cin >> a[i];
    }

    double left, right;
    cout << "Left, right: \n";
    cin >> left >> right;

    cout << "Zeros of polynomial: \n";

    double x = left;
    double move = 0.1;
    while (x < right)
    {
        if (horner(deg, x, a) * horner(deg, x + move, a) < 0)
        {
            cout << zero_of_a_func(deg, a, x, x + move) << '\n';
        }
        x += move;
    }

    return 0;
}