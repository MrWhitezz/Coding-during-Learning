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