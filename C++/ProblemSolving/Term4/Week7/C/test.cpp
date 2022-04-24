#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005

int n, father[maxn];

struct edge{
    ll src, dst;
    ll val;
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

ll krusal(){
    init();
    assert(n != 0 && Edges.size() >= n - 1);
    sort(Edges.begin(), Edges.end(), cmp);
    ll ans = 0;
    int k = 0, i = 0;
    while (k < n - 1){
        if(unionSet(Edges[i].src, Edges[i].dst)){
            k++;
            ans += Edges[i].val;
        }
        i++;
    }
    return ans;
}

struct point {
    ll x;
    ll y;
    int num;
};

vector<vector<point>> v;

void try_add(point p, vector<point> &v, int pos){
    if (pos >= 0 && pos < v.size()){
        if (v[pos].num == p.num){
            try_add(p, v, pos - 1);
            try_add(p, v, pos + 1);
            return;
        }
        assert(v[pos].num != p.num);
        ll dist = (p.x - v[pos].x) * (p.x - v[pos].x) + (p.y - v[pos].y) * (p.y - v[pos].y);
        assert(dist > 0);
        Edges.push_back({p.num, v[pos].num, dist});
    }
}

void add_neibor(point p, vector<point> &line){
    assert(!line.empty());
    if (line[0].x > p.x){
        try_add(p, line, 0);
        return;
    }
    int l = 0, r = line.size() - 1;
    while (l + 1 < r){
        int mid = (l + r) / 2;
        if (line[mid].x > p.x) r = mid;
        else l = mid;
    }
    if (l + 1 != r){
        assert(line.size() == 1);
        try_add(p, line, 0);
        return;
    }
    assert(line[l].x <= p.x);
    try_add(p, line, l);
    try_add(p, line, r);
}

int main(){
    cin >> n;
    v.resize(11);
    for (int i = 1; i <= n; i++) {
        point p;
        cin >> p.x >> p.y;
        p.num = i;
        v[p.y].push_back(p);
    }
    for (int y = 0; y < 11; y++) {
        sort(v[y].begin(), v[y].end(), [](point a, point b) {
            return a.x < b.x;
        });
    }
    for (int y = 0; y < 11; y++) {
        for (int i = 0; i < v[y].size(); i++) {
            for (int ly = 0; ly < 11; ly++) {
                if (v[ly].empty()) continue;
                add_neibor(v[y][i], v[ly]);
            }
        }
    }

    cout << krusal() << endl;

}
