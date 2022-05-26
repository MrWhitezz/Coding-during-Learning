#include <bits/stdc++.h>
using namespace std;
#define maxn 105
#define maxl 15
vector<string> strs;
vector<vector<int>> eds;
int dist[maxn][maxn];
int dp[maxl][maxl];
int n;
int ans = 0;

void dfs(int v);


int father[maxn];

struct edge{
    int src, dst;
    int val;
};

vector<edge> Edges;

bool cmp(edge a, edge b){return a.val < b.val;}

int findFather(int a){
    int t = a;
    while(a != father[a])a = father[a]; //找到根节点
    return a;
}

void init(){
    for(int i = 1; i <= n; i++)father[i] = i;
}

int unionSet(int x, int y){ //和并查集一样，如果将根合并
    int fx = findFather(x);
    int fy = findFather(y);
    if(fx != fy){
        father[fx] = fy;
        return  1;
    }return 0;
}

int krusal(){
    init();
    assert(n != 0 && Edges.size() >= n - 1);
    sort(Edges.begin(), Edges.end(), cmp);
    int ans = 0;
    int k = 0, i = 0;
    while (k < n - 1){
        if(unionSet(Edges[i].src, Edges[i].dst)){
            k++;
            int u = Edges[i].src;
            int v = Edges[i].dst;
            eds[u].push_back(v);
            eds[v].push_back(u);
            ans += Edges[i].val;
        }
        i++;
    }
    return ans;
}


int edit_dis(string s1, string s2) {
    memset(dp, 0, sizeof(dp));
    int m = s1.size(), n = s2.size();
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    return dp[m][n];
}

int pre = -1, cur = -1;
bool vis[maxn];

void solve(){
    cin >> n;
    strs.resize(n + 5);
    eds = vector<vector<int>>(n + 5);
    Edges = vector<edge>(n + 5);
    for (int i = 1; i <= n; i++) cin >> strs[i];
    memset(dist, 0, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // can be optimized
            dist[i][j] = edit_dis(strs[i], strs[j]);
            Edges.push_back({i, j, dist[i][j]});
        }
    }
    krusal();
    memset(vis, 0, sizeof(vis));
    ans = 0;
    pre = -1, cur = -1;
    dfs(1);
    assert(cur != 1);
    ans += dist[cur][1];
    cout << ans << endl;
}



void dfs(int v){
    vis[v] = true;
    cur = v;
    if (pre != -1) {
        ans += dist[pre][cur];
        // printf("pre = %d, cur = %d, dist = %d\n", pre, cur, dist[pre][cur]);
    }
    else assert(v == 1);

    for (int i = 0; i < eds[v].size(); i++) {
        int u = eds[v][i];
        if (!vis[u]) {
            pre = cur;
            dfs(u);
        }
    }
}


int main(){
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}