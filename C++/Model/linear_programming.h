// m个约束，n个变量
// 第i个约束，sum(a[i][j]*x[j])+a[i][0]>=0
// solve函数返回约束是否有解
// 若有解，则使得目标函数 sum(a[0][j]*x[j]) 最大化
#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define REP(i,n) FOR(i,1,n)
#define REP_0N(i,n) FOR(i,0,n)
using namespace std;
typedef long double ld;
#define maxn 505
#define N 505
ld a[105][105];
int n,m,id[N],tp[N],nn;
const ld eps=1e-9;
const ld inf=1e12;
int T;
void pivot(int r,int c) {
    swap(id[r+n],id[c]);
    ld t=-a[r][c];
    a[r][c]=-1;
    REP_0N(i,n) a[r][i]/=t;
    REP_0N(i,m)
    if (a[i][c]&&r!=i) {
        t=a[i][c];
        a[i][c]=0;
        REP_0N(j,n) a[i][j]+=t*a[r][j];
    }
}
bool solve() {
    ld t;
    REP(i,n) id[i]=i;
    while (true) {
        int i=0,j=0; ld w=-eps;
        REP(k,m) if (a[k][0]<w) w=a[i=k][0];
        if (!i) break;
        REP(k,n) if (a[i][k]>eps) {j=k; break;} // check bound not to be two small
        if (!j) return false;
        pivot(i,j);
    }
    while (true) {
        int i=0,j=0; ld w=eps;
        REP(k,n) if (a[0][k]>w) w=a[0][j=k];
        if (!j) break;
        w=inf;
        REP(k,m) if (a[k][j]<-eps&&(t=-a[k][0]/a[k][j])<w) w=t,i=k;
        if (!i) return true;
        pivot(i,j);
    }
    FOR(i,n+1,n+m) tp[id[i]]=i-n;
    REP(i,n) x[i]=tp[i]?a[tp[i]][0]:0;
    return true;
}