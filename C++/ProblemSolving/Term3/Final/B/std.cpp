#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, S, tmp;
#define maxs 60005
ll ans[maxs];
int main(){
    cin >> n >> S;
    vector<ll> v; v.clear();
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        if (tmp < S){
            v.push_back(tmp);
        }
    }
    for (int i = 0; i < v.size(); ++i){
        for (int j = i + 1; j < v.size(); ++j){
            for (int k = j + 1; k < v.size(); ++k){
                tmp = v[i] + v[j] + v[k];
                if (tmp <= S)
                    ans[tmp]++;
            }
        }
    }
    for (int i = 1; i <= S; ++i)
        cout << ans[i] << " ";
}