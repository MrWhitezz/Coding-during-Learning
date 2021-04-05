#include<bits/stdc++.h>
using namespace std;
long long rp(vector<long long> v);
int main()
{
    vector<long long> v;
    long long n, val;
    cin >> n;
    for (long long i = 0; i < n; ++i){
        cin >> val;
        v.push_back(val);
    }
    cout << rp(v);
    return 0;
}
long long rp(vector<long long> v){
    if (v.size() == 1) return 0;
    long long mid = v.size() / 2;
    vector<long long> v1(v.begin(), v.begin() + mid), v2(v.begin() + mid, v.end());
    long long val1 = rp(v1), val2 = rp(v2), res = val1 + val2;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    auto it2 = v2.begin();
    for (auto it1 = v1.begin(); it1 != v1.end();){
            if (it2 == v2.end()) {res += (v1.end() - it1) * v2.size(); break;}
            if (*it1 <= *it2) {res += it2 - v2.begin(); ++it1; continue;}
            else {++it2; continue;}
    }
    return res;
}