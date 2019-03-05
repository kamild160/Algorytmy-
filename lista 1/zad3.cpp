#include <iostream>

double oblicz(double a[], int n, double x)
{
    double result = 0;

    for(int i = n; i > 0; --i)
    {
        result = (a[i] + result) * x;
    }

    return result + a[0];
}


int main()
{
    int n = 3;
    double x = 10;
    double a [n] = {5, 5, 3};

    std::cout << oblicz(a, n, x) << std::endl;
}
