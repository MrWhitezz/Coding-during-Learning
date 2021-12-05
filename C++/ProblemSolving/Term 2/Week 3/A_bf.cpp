#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int n, val, res;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> val;
        v.push_back(val);
    }
    for (auto it = v.begin(); it != v.end(); ++it){
        for (auto jt = it + 1; jt != v.end(); ++jt){
            if (*it > *jt) ++res;
        }
    }
    cout << res;
    return 0;
}