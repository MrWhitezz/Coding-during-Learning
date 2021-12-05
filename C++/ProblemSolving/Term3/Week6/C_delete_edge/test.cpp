#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
const ll P = 1e9 + 7;
int k = 2;// size of matrix
struct M
{
    ll v[3][3];
    M(){
        memset(v, 0, sizeof(v));
    }
    friend M operator* (M a, M b){
        M c;
        for (int i = 1; i <= k; ++i)
            for (int j = 1; j <= k; ++j)
                for (int l = 1; l <= k; ++l)
                    c.v[i][j] = (c.v[i][j] + a.v[i][l] * b.v[l][j]) % P;
        return c;
    }
    friend M operator^(M a, ll b){
        M ans;
        for (int i = 1; i <= k; ++i)
            ans.v[i][i] = 1;
        for (; b; b >>= 1, a = a * a)
            if (b & 1) ans = ans * a;
        return ans;
    }
};
ll x[3];

int main(){
    cin >> N;
    M A;
    A.v[1][1] = 4, A.v[1][2] = 1;
    A.v[2][1] = 2, A.v[2][2] = 1;
    A = A ^(N - 1);
    cout << (A.v[1][1] + A.v[1][2]) % P;  
}