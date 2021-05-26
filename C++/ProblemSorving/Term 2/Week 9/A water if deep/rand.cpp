#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << 1 << endl;
    srand((unsigned)time(NULL));
    int n = rand() % 10, m = rand() % 50 + 2;
    cout << n << " " <<  m << endl;
    for (int i = 0; i < n; ++i)
        cout << rand() % m << " ";
    cout << endl;
    return 0;
}