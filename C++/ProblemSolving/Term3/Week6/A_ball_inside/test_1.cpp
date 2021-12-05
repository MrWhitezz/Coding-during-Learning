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
#define N 505 // N > n + m
ld a[320][10];
ld x[10];
int n = 3,m,id[N],tp[N],nn;
const ld eps=1e-9;
const ld inf=1e12;
void pivot(int r,int c) { // a[r][0] smallest, a[r][c] normal
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
        REP(k,m) if (a[k][0]<w) w=a[i=k][0]; // a[i][0] smallest among a[][0]
        if (!i) break; // have solution
        REP(k,n) if (a[i][k]>eps) {j=k; break;} // check bound not to be two small
        if (!j) return false;
        pivot(i,j);
    }
    while (true) {
        int i=0,j=0; ld w=eps;
        REP(k,n) if (a[0][k]>w) w=a[0][j=k]; // a[0][j] largest among a[0][], j waiting for pivot
        if (!j) break;
        w=inf;
        REP(k,m) if (a[k][j]<-eps&&(t=-a[k][0]/a[k][j])<w) w=t,i=k; // choose the smallest -a[k][0] / a[k][j]
        if (!i) return true;
        pivot(i,j);
    }
    FOR(i,n+1,n+m) tp[id[i]]=i-n;
    REP(i,n) x[i]=tp[i]?a[tp[i]][0]:0;
    return true;
}
ld cstr[105][4];
int T, line;

bool try_sol(ld dis){
    memset(a, 0, sizeof(a));
    memset(x, 0, sizeof(x));
    for(int i = 1; i <= line; ++i){
        a[i][0] = cstr[i][0];
        for (int j = 1; j <= 3; ++j)
            a[i][j] = -cstr[i][j];
    }
    for (int i = 1; i <= line; ++i){
        a[i + line][0] = -dis * sqrtl(cstr[i][1] * cstr[i][1] + cstr[i][2] * cstr[i][2] + cstr[i][3] * cstr[i][3]) + cstr[i][0];
        for (int j = 1; j <= 3; ++j)
            a[i + line][j] = -cstr[i][j];
    }
    int t1 = 2 * line + 1;
    a[t1][0] = a[t1 + 1][0] = a[t1 + 2][0] = -dis;
    a[t1][1] = a[t1 + 1][2] = a[t1 + 2][3] = 1;
    m = t1 + 2;
    return solve();
}
int main(){
    cin >> T;
    while (T--){
       cin >> line;
       for (int i = 1; i <= line; ++i){
            cin >> cstr[i][1] >> cstr[i][2] >> cstr[i][3] >> cstr[i][0]; 
       } 
       ld lft = 0, rgt = 1e9, error = 1e-9;
       if (try_sol(rgt)) printf("Infinity\n");
       else if (!try_sol(lft)) printf("0.0000\n");
       else {
           while (rgt - lft > error){
               ld mid = (rgt + lft) / 2;
               if (try_sol(mid)) lft = mid;
               else rgt = mid;
           }
           printf("%.4lf\n", (double)rgt);
       }
    }

    return 0;
}