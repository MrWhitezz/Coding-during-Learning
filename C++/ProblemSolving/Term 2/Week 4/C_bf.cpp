#include<bits/stdc++.h>
using namespace std;
int n, V;
using ll = long long;
vector<pair<int, int>> items;
void dfs_bf(int pos, int wt, ll val);
ll res = 0;
int main()
{
    cin >> n >> V;
    int tmp_wt; ll tmp_val;
    for (int i = 0; i < n; ++i){
        cin >> tmp_wt >> tmp_val;
        items.push_back({tmp_wt, tmp_val});
    }
    dfs_bf(0, 0, 0);
    cout << res;
    return 0;
}
void dfs_bf(int pos, int wt, ll val){
    if (wt > V) return;
    if (pos == n){
        res = max(res, val);
        return;
    }
    dfs_bf(pos + 1, wt + items[pos].first, val + items[pos].second);
    dfs_bf(pos + 1, wt, val);
}
