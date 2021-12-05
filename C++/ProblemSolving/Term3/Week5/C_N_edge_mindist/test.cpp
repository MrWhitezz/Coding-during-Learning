#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int M_Size, N, T, S, E, tot = 0;
int w, U, V;
struct M
{
    int v[105][105];
    M(){
        memset(v, 0x3f, sizeof(v));
    }
    friend M operator* (M a, M b){
        M c;
        for (int i = 1; i <= M_Size; ++i)
            for (int j = 1; j <= M_Size; ++j)
                for (int l = 1; l <= M_Size; ++l)
                    c.v[i][j] = min(c.v[i][j], a.v[i][l] + b.v[l][j]);
        return c;
    }
    friend M operator^(M a, int b){
        assert(b >= 2);
        b = b - 1;
        M ans; ans = a;
        for (; b; b >>= 1, a = a * a)
            if (b & 1) ans = ans * a;
        return ans;
    }
};
int num[1005];
int main(){
    cin >> N >> T >> S >> E; 
    M A;
    for (int i = 1; i <= T; ++i){
        cin >> w >> U >> V;
        if (num[U] == 0) num[U] = ++tot;
        if (num[V] == 0) num[V] = ++tot;
        A.v[num[U]][num[V]] = min(A.v[num[U]][num[V]], w);
        A.v[num[V]][num[U]] = min(A.v[num[V]][num[U]], w);
    }
    M_Size = tot;
    if (N >= 2)
        A = A ^ N;
    int ans = A.v[num[S]][num[E]];
    printf("%d", ans);
    return 0;
}