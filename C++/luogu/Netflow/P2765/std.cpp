#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define sz 1000000

const int MAXN = sz + 5;
const int INF = 1e9;

struct Edge {
    int to, cap, rev;
    Edge(int to, int cap, int rev): to(to), cap(cap), rev(rev) {}
};

std::vector<Edge> vec[MAXN];
std::queue<int> que;
int level[MAXN], pre[MAXN];

inline void addedge(int u, int v, int cap) {
    vec[u].push_back(Edge(v, cap, vec[v].size()));
    vec[v].push_back(Edge(u, 0, vec[u].size() - 1));
}

// Dinic 

inline bool bfs(int s, int t) {
    memset(level, -1, sizeof level);
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].to;
            if(level[v] == -1 && vec[u][i].cap > 0) {
                level[v] = level[u] + 1;
                que.push(v);
            }
        }
    }
    return level[t] != -1;
}

inline int dfs(int u, int t, int left) {
    if(u == t) return left;
    for(int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i].to;
        if(vec[u][i].cap > 0 && level[v] == level[u] + 1) {
            int d = dfs(v, t, std::min(left, vec[u][i].cap));
            if(d > 0) {
                vec[u][i].cap -= d;
                vec[v][vec[u][i].rev].cap += d;
                // u representes the ball number floor(u / 2), and so as v
                pre[u >> 1] = v >> 1;
                return d;
            }
        }
    }
    return 0;
}

inline int max_flow(int s, int t) {
    int flow = 0;
    while(bfs(s, t)) {
        int f;
        while((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}

int n, s = sz + 1, t = sz + 2, pillar = 0, now = 0, head[10005];
bool vis[sz + 5];

int main() {
    scanf("%d", &n);
    // add more pillars if possible
    while(pillar <= n) {
        now++; // try to add one more ball
        addedge(s, now << 1, 1);
        addedge((now << 1) | 1, t, 1);
        // find the ball which can connect to this
        for(int i = sqrt(now) + 1; i * i < (now << 1); i++) {
            addedge((i * i - now) << 1, (now << 1) | 1, 1);
        }
        int flow = max_flow(s, t);
        if(!flow) {
            // when it needs to add more pillars, record the first ball added to the next pillar
            head[++pillar] = now;
        }
    }
    printf("%d\n", now - 1);
    for(int i = 1; i <= n; i++) {
        if(!vis[head[i]]) {
            for(int u = head[i]; u != 0 && u != (t >> 1); u = pre[u]) {
                vis[u] = true;
                printf("%d ", u);
            }
            printf("\n");
        }
    }
    return 0;
}