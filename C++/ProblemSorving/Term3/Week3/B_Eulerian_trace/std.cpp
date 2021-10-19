#include<bits/stdc++.h>
using namespace std;
#define NSize 500
int F, x, y, odd, start, minn, maxn;
bool is_odd, is_minn = false, is_maxn = false;
int edge[NSize + 1][NSize + 1];
vector<int> deg(NSize + 1);
vector<int> ans;
void dfs(int v);
int main(){
    cin >> F;
    for (int i = 1; i <= NSize; ++i)
        for (int j = 1; j <= NSize; ++j)
            edge[i][j] = 0;
    for (int i = 0; i < F; ++i){
        cin >> x >> y;
        edge[x][y]++, edge[y][x]++;
        deg[x]++, deg[y]++;
    }

    is_odd = false;
    for (int i = 1; i <= NSize; ++i){
        if (deg[i] & 1){
            is_odd = true;
            odd = i;
            break;
        }
    }
    for (int i = 1; i <= NSize && !is_minn; ++i)
        for (int j = 1; j <= NSize && !is_minn; ++j){
            if (edge[i][j]) {minn = i; is_minn = true;}
        }
    for (int i = NSize; i >= 1 && !is_maxn; --i)
        for (int j = 1; j <= NSize && !is_maxn; ++j)
            if (edge[i][j]) {maxn = i; is_maxn = true;}
    start = is_odd ? odd : minn;

    dfs(start);

    for(auto it = ans.rbegin(); it != ans.rend(); ++it)
        cout << *it << endl;
}
void dfs(int v){
    for (int i = 1; i <= NSize; ++i){
        if (edge[v][i]){
            edge[v][i]--, edge[i][v]--;
                dfs(i);
        }
    }
    ans.push_back(v);
}