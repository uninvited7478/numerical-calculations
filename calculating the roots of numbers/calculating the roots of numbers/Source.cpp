#include<iostream> 
#include<cmath> 
using namespace std;

const double eps = 1e-12;

double squareRoot(double a)
{
    double x1 = a;
    double x2 = a / 2;

    int cnt = 0;
    while (fabs(x2 - x1) >= eps && cnt < 10000)
    {
        double tmp = x1;
        x1 = x2;
        x2 = (tmp + a / tmp) / 2;
        cnt++;
    }

    return x2;
}

double nRoot(double a, int n)
{
    double x1 = a;
    double x2 = a / 2;

    int cnt = 0;
    while (fabs(x2 - x1) >= eps && cnt < 1000000)
    {
        double tmp = x1;
        x1 = x2;
        x2 = (((double)n - 1.0) * tmp + a / pow(tmp, n - 1)) / (double)n;
        cnt++;
    }

    return x2;
}


int main()
{
    //    for (int i = 1; i <= 100; ++i) 
    //    { 
    //        cout << i << ": "<< squareRoot((double) i) << '\n'; 
    //    } 

    for (int i = 1; i <= 100; ++i)
    {
        cout << i << ": " << nRoot((double)i, 4) << '\n';
    }

    return 0;
}