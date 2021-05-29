#include<bits/stdc++.h>
using namespace std;
const int Max = 10;
int main()
{
    srand((unsigned)time(NULL));
    int n = rand() % Max + 1;
    cout << n << endl;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i + 1;
    for (int i = 0, j = n; j > 0; --j){
        i = rand() % j;
        cout << v[i] << " ";
        v[i] = v[j - 1];
        v.pop_back();
    }

    return 0;
}