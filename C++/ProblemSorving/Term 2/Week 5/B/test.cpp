#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];  
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    multiset<int> S;
    S.insert(a[0]);
    auto it = S.begin();
    cout << a[0] << endl;
    for (int i = 1; i + 1 < n; i += 2){
        S.insert(a[i]);
        S.insert(a[i + 1]);
        if ((a[i] <= *it && a[i + 1] > *it) || (a[i] > *it && a[i + 1] <= *it ))
            {cout << *it << endl; continue;}
        else if (a[i] <= *it && a[i + 1] <= *it){
            it--;
            cout << *it << endl; continue;
        }
        else{
            it++;
            cout << *it << endl; continue;
        }
    }
    return 0;
}