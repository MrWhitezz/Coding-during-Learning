#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; i += 2){
        sort(a, a + i);
        cout << a[i / 2] << endl;
    }
    return 0;
}