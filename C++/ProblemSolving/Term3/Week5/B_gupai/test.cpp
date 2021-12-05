#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m, P;
int M_Size, n;
struct M
{
    ll v[9][9];
    M(){
        memset(v, 0, sizeof(v));
    }
    friend M operator* (M a, M b){
        M c;
        for (int i = 1; i <= M_Size; ++i)
            for (int j = 1; j <= M_Size; ++j)
                for (int l = 1; l <= M_Size; ++l)
                    c.v[i][j] = (c.v[i][j] + a.v[i][l] * b.v[l][j]) % P;
        return c;
    }
    friend M operator^(M a, ll b){
        M ans;
        for (int i = 1; i <= M_Size; ++i)
            ans.v[i][i] = 1;
        for (; b; b >>= 1, a = a * a)
            if (b & 1) ans = ans * a;
        return ans;
    }
};
ll x[9];
int main(){
    cin >> n >> m >> P;    
    M_Size = n == 2 ? 4 : 8;
    M a;
    if (n == 1){
        int ans = m & 1 ? 0 : 1;
        printf("%d\n", ans);
        return 0;
    }
    if (n == 2){
        a.v[1][1] = 1; a.v[1][4] = 1;
        a.v[2][3] = 1;
        a.v[3][2] = 1;
        a.v[4][1] = 1;
    }
    if (n == 3){
        a.v[1][2] = 1, a.v[1][5] = 1, a.v[1][8] = 1; 
        a.v[2][1] = 1, a.v[2][7] = 1;
        a.v[3][6] = 1;
        a.v[4][5] = 1;
        a.v[5][1] = 1, a.v[5][4] = 1;
        a.v[6][3] = 1;
        a.v[7][2] = 1;
        a.v[8][1] = 1;
    }
    x[1] = 1;
    a = a ^ m;
    ll ans = a.v[1][1];
    printf("%d\n", ans);
    
    return 0;
}