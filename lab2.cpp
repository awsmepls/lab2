#include <iostream>

using namespace std;

long double doubleFactorial(long double n)
{
    if (n <= 0)
        return 1;
    else
        return n * doubleFactorial(n - 2);
}

long double power(long double base, int exponent)
{
    long double result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

long double t(long double x)
{
    long double numerator = 0;
    long double denominator = 0;

    for (int k = 0; k <= 10; k++)
    {
        numerator += power(x, 2 * k + 1) / doubleFactorial(2 * k + 1);
        denominator += power(x, 2 * k) / doubleFactorial(2 * k);
    }

    return numerator / denominator;
}

int main()
{
    long double y;
    cin >> y;

    long double result = (7 * t(0.25) + 2 * t(1 + y)) / (6 - t(pow(y, 2) - 1));
    cout.precision(10);
    cout << fixed << result << endl;

    return 0;
}