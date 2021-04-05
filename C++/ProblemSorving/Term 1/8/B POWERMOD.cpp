#include<iostream>
using namespace std;
long long powermod(long long a, long long b, long long m);
int main()
{
    long long a, b, m;
    cin >> a >> b >> m;
    cout << powermod(a % m, b, m);
    return 0;
}
long long powermod(long long a, long long b, long long m)
{
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {long long temp = powermod(a, b / 2, m); return temp * temp % m;}
        else {long long temp = powermod(a, b / 2, m); return (temp * temp % m) * a % m;}
}
