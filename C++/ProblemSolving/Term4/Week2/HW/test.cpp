#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define maxn 5000
int n;
ll b;
ll c[maxn];
ll w[maxn];
struct triple{
    ll k;
    ll w;
    set<int> T;
};
vector<triple> TRIPLE;
vector<triple> SET;
ll max_k(){
    ll res = 0;
    for (auto s : SET){
        res = max(res, s.k);
    }
    return res;
}
void reduce_k(ll k){
    for (auto it = SET.begin(); it != SET.end(); ++it){
        if (it->k == k){
            for (auto jt = it + 1; jt != SET.end(); ++jt){
                if (jt->k == k){
                    if (it->w > jt->w) SET.erase(it);
                    else               SET.erase(jt);
                    reduce_k(k);
                    return;
                }
            }
        }
    }
}

int main(){
    cin >> n >> b;
    for (int i = 1; i <= n; ++i){
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    TRIPLE.push_back({0, 0,{}});
    if (w[1] <= b) TRIPLE.push_back({c[1], w[1], {1}});
    for (int i = 1; i < n; ++ i){
        SET = TRIPLE;
        for (auto tr : TRIPLE){
            if (tr.w + w[i + 1] <= b){
                set<int> T1 = tr.T; T1.insert(i + 1);
                SET.push_back({tr.k + c[i + 1], tr.w + w[i + 1], T1});
            }
        }
        ll K = max_k();
        for (int k = 1; k <= K; ++k){
            reduce_k(k);
        }
        TRIPLE = SET;
    }
    SET = TRIPLE;
    cout << max_k() << endl; 
}