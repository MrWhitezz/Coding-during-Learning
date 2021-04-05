#include<bits/stdc++.h>
using namespace std;
int n, V;
using ll = long long;
vector<pair<int, ll>> items;
vector<pair<int, ll>> first_Half;
map<int, ll> first_Malf;
void dfs_1(int pos1, int wt, ll val);
void dfs_2(int pos2, int wt, ll val);
ll res = 0;
int main()
{
    cin >> n >> V;
    int tmp_wt; ll tmp_val;
    for (int i = 0; i < n; ++i){
        cin >> tmp_wt >> tmp_val;
        items.push_back({tmp_wt, tmp_val});
    }
    sort(items.begin(), items.end());
    dfs_1(0, 0, 0);
    sort(first_Half.begin(), first_Half.end());
    // This technique is extremely important
    int len = 1;
    for (int i = 0; i < first_Half.size(); ++i)
        if (first_Half[len - 1].second < first_Half[i].second)
            first_Half[len++] = first_Half[i];
    for (int i = 0; i < len; ++i)
        first_Malf[first_Half[i].first] = first_Half[i].second;

    dfs_2(n / 2, 0, 0);
    cout << res;

    return 0;
}
void dfs_1(int pos1, int wt, ll val){
    if (pos1 == n / 2) {first_Half.push_back({wt, val}); return;}
    if (wt + items[pos1].first > V) {first_Half.push_back({wt, val}); return;}
    dfs_1(pos1 + 1, wt + items[pos1].first, val + items[pos1].second);
    dfs_1(pos1 + 1, wt, val);
}
void dfs_2(int pos2, int wt, ll val){
    if (pos2 == n){
        auto it = first_Malf.upper_bound(V - wt);
        if (it == first_Malf.begin()) res = max(res, val);
        else res = max(res, val + (--it)->second);
        return;
    }
    if (wt + items[pos2].first > V) {dfs_2(n, wt, val); return;}
    dfs_2(pos2 + 1, wt + items[pos2].first, val + items[pos2].second);
    dfs_2(pos2 + 1, wt, val);
}
