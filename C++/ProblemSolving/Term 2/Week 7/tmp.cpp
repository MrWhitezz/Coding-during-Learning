#include<iostream>
using namespace std;
int K;
int main()
{
    cin >> K;
    double fac[K + 5], exp[K + 5];
    fac[0] = exp[0] = 1;
    double res = 0;
    for (int i = 1; i <= K + 3; ++i){
        fac[i] = i * fac[i - 1];
        exp[i] = K * exp[i - 1];
    }
        
    for (int i = 2; i <= K + 1; ++i)
        res += fac[K] * i * (i - 1) / exp[i] / fac[K - i + 1];
    cout << res;
    return 0;
}