#include<bits/stdc++.h>
using namespace std;
const int P = 8;
int main()
{
    srand((unsigned)time(NULL));
    int n = rand() % P + 1;
    cout << n << endl; 
    string s;
    for (int i = 0; i < n; ++i)
        s += ('a' + rand() % P);
    cout << s;
    return 0;
}