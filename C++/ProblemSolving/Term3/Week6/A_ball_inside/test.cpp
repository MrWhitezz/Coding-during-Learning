//fail
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
int n,m,id[N],tp[N],nn;
const ld eps=1e-9;
const ld inf=1e12;
int T;
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
ld a1, b1, c1, d1;
int main(){
    cin >> T;
    n = 4; // x, y, z, R
    while (T--){
        cin >> m;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= m; ++i){
            cin >> a1 >> b1 >> c1 >> d1;
            a[i][0] = d1;
            a[i][1] = -a1, a[i][2] = -b1, a[i][3] = -c1;
            // -R <= (ax + by + cz - d / sqrt(a^2 + ...)) <= R
            a[m + i][4] = a[2 * m + i][4] = sqrtl(a1 * a1 + b1 * b1 + c1 * c1);
            a[m + i][1] = -a1, a[m + i][2] = -b1, a[m + i][3] = -c1, a[m + i][0] = d1;
            a[2 * m + i][1] = a1, a[2 * m + i][2] = b1, a[2 * m + i][3] = c1, a[2 * m + i][0] = -d1;
        }
        // x, y, z >= R
        a[3 * m + 1][1] = 1, a[3 * m + 1][4] = -1;
        a[3 * m + 2][2] = 1, a[3 * m + 2][4] = -1;
        a[3 * m + 3][3] = 1, a[3 * m + 3][4] = -1;
        // maximize R
        a[0][4] = 1;
        memset(x, 0, sizeof(x));

        m = 3 * m + 3;
        if (solve()){
            printf("%4f\n", x[4]);
        }
        else printf("infinity\n");
    }
    return 0;
}