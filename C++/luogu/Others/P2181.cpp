#include<iostream>
using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    unsigned long long  point = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
    cout << point << endl;
    return 0;
}
