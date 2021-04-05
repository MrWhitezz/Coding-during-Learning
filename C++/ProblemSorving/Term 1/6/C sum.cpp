#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long n, sum;
    sum = 0;
    cin >> n;
    for (long long i = 1; i < n + 1; i = n / (n / i) + 1)
        sum = (sum + (n / i) * (n / (n / i) - i + 1) ) % 233;
    cout << sum;

    return 0;
}

