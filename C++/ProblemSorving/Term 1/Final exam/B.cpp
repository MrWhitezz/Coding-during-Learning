#include<bits/stdc++.h>
using namespace std;
int n, k, T;
int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> k >> n;
        while (!(n % 2))
        {
            n /= 2;
            k--;
        }
        cout << k << endl;
    }
    return 0;
}

