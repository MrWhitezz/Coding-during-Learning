#include<bits/stdc++.h>
using namespace std;
const int P = 15, Q = 100;
int main()
{
    srand((unsigned)time(NULL));
    int n = rand() % P + 1;
    cout << 1 << endl;
    cout << n << endl; 
    for (int i = 0; i < n; ++i)
        cout << rand() % Q << " ";
    return 0;
}