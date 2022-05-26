// correct, but too slow
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 1e9 + 7;
#define maxlog 21
#define maxn 1000005
int n;

int Fmax[maxn][maxlog];
int Fminl[maxn][maxlog];
int Fminr[maxn][maxlog];
int For[maxn][maxlog];
int a[maxn];

void init(){
    for (int j = 0; j < maxlog; ++j){
        Fmax[n][j]  = a[n];
        Fminr[n][j] = a[n];
        For[n][j]   = a[n];
    }
    for (int i = n - 1; i >= 1; --i) {
        Fmax[i][0]  = max(a[i], a[i + 1]);
        Fminr[i][0] = min(a[i], a[i + 1]);
        For[i][0]   = a[i] | a[i + 1];
    }

    for (int i = n - 1; i >= 1; --i){
        for (int j = 1; j < maxlog; ++j){
            int dis = 1 << (j - 1);
            if (i + dis > n){
                Fmax[i][j]  = max(Fmax[i + 1][j], a[i]);
                Fminr[i][j] = min(Fminr[i + 1][j], a[i]);
                For[i][j]   = For[i + 1][j] | a[i];
                break;
            }
            else {
                Fmax[i][j]  = max(Fmax[i + dis][j - 1], Fmax[i][j - 1]);
                Fminr[i][j] = min(Fminr[i + dis][j - 1], Fminr[i][j - 1]);
                For[i][j]   = For[i + dis][j - 1] | For[i][j - 1];
            }
        }
    }

    for (int j = 0; j < maxlog; ++j)
        Fminl[1][j] = a[1];
    for (int i = 2; i <= n; ++i)
        Fminl[i][0] = min(a[i], a[i - 1]);

    for (int i = 2; i <= n; ++i){
        for (int j = 1; j < maxlog; ++j){
            int dis = 1 << (j - 1);
            if (i - dis < 1){
                Fminl[i][j] = min(Fminl[i - 1][j], a[i]);
                break;
            }
            else 
                Fminl[i][j] = min(Fminl[i - dis][j - 1], Fminl[i][j - 1]);
        }
    }
}

int intlog(int x){
    int res = 0;
    while (x > 0){
        x >>= 1;
        res++;
    }
    return res;
}

int find_r(int pos, int l, int r){
    if      (l == r)     return l;
    else if (l + 1 == r) return l;
    int dis = r - l;
    int j = intlog(dis - 1) - 1;
    if (Fminr[l][j] >= a[pos])
        return find_r(pos, l + (1 << j), r);
    else
        return find_r(pos, l, l + (1 << j));
}

int find_l(int pos, int l, int r){
    if      (l == r)     return r;
    else if (l + 1 == r) return r;
    int dis = r - l;
    int j = intlog(dis - 1) - 1;
    if (Fminl[r][j] >= a[pos])
        return find_l(pos, l, r - (1 << j));
    else
        return find_l(pos, r - (1 << j), r);

}

int find_max(int tmp, int l, int r){
    if (l == r) return max(tmp, a[l]);
    if (l + 1 == r) return max(tmp, max(a[l], a[r]));
    
    int dis = r - l;
    int j = intlog(dis - 1) - 1;
    tmp = max(tmp, Fmax[l][j]);
    return find_max(tmp, l + (1 << j), r);
}

int find_or(int tmp, int l, int r) {
    if (l == r) return tmp | a[l];
    else if (l + 1 == r) return tmp | a[l] | a[r];
    int dis = r - l;
    int j = intlog(dis - 1) - 1;
    tmp = tmp | For[l][j];
    return find_or(tmp, l + (1 << j), r);
}

int main(){
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        ll p, q, x, y, z;
        cin >> p >> q >> x >> y >> z;
        a[1] = p;
        a[2] = q;
        for (int i = 3; i <= n; i++){
            a[i] = (a[i - 2] * x + a[i - 1] * y + z) % 1000000LL + 1; 
        }
        a[0] = a[1], a[n + 1] = a[n];

        init();

        __int128_t V = 0;
        for (int i = 1; i <= n; ++i){
            int l = find_l(i, 0, i);
            int r = find_r(i, i, n + 1);
            

            __int128_t A = find_max(0, l, r);
            __int128_t B = a[i];
            __int128_t C = r - l + 1;
            __int128_t D = find_or(0, l, r);
            // __int128_t A = 0, B = 0, C = 0, D = 0;

            V = max(V, (A - B) * B * C * D);
        }
        V = V % P;
        cout << ((ll)V) << endl;

    }
}