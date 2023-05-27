#include <iostream> 
#include <vector> 
#include <cmath> 
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

double field_rect(int deg, vector<double>& a, double start, double end)
{
    const double N = 1000;
    double d = (end - start) / N;

    double field = 0;

    for (double i = start; i + d <= end; i += d)
    {
        double mid = (i + i + d) / 2;
        field += (fabs(horner(deg, a, mid)) * d);
    }
    return field;
}

double field_trap(int deg, vector<double>& a, double start, double end)
{
    const double N = 1000;
    double d = (end - start) / N;

    double field = 0;

    for (double i = start; i + d <= end; i += d)
    {
        field += (((fabs(horner(deg, a, i)) + fabs(horner(deg, a, i + d))) * d) / 2);
    }
    return field;
}

double sin_field_rect(double start, double end)
{
    const double N = 1000;
    double d = (end - start) / N;

    double field = 0;

    for (double i = start; i + d <= end; i += d)
    {
        double mid = (i + i + d) / 2;
        field += (fabs(sin(mid)) * d);
    }
    return field;
}

double sin_field_trap(double start, double end)
{
    const double N = 1000;
    double d = (end - start) / N;

    double field = 0;

    for (double i = start; i + d <= end; i += d)
    {
        field += ((fabs(sin(i)) + fabs(sin(i + d)) * d) / 2);
    }
    return field;
}

int main()
{
    cout << "Sin field rect: " << sin_field_rect(0, M_PI) << '\n';
    cout << "Sin field trap: " << sin_field_rect(0, M_PI) << '\n';

    int degG = 7;
    vector<double> G = { 1, -3, -4, 12, -1, 3, 4, -12 };
    cout << "G field rect: " << field_rect(degG, G, -1, 1) << '\n';
    cout << "G field trap: " << field_trap(degG, G, -1, 1) << '\n';

    int degH = 3;
    vector<double> H = { 1, -1, -4, 4 };

    cout << "H field rect: " << field_rect(degH, H, -2, 2) << '\n';
    cout << "H field trap: " << field_trap(degH, H, -2, 2) << '\n';


    return 0;
}