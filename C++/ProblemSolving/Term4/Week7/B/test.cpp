#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nmax 1005
const ll P = 1e9 + 7;
int N;
ll dp[nmax][nmax];
ll H[nmax];
ll sum[nmax];
ll hmin = nmax; ll hmax = 0;
ll clc(){
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= N; ++i){
        for (int j = 0; j <= H[i]; ++j){
            if (i == 1) dp[i][j] = 1;
            else {
                ll rem = H[i] - j;
                dp[i][j] = sum[rem];
            }
        }
        memset(sum, 0, sizeof(sum));
        sum[0] = dp[i][0];
        for (int j = 1; j <= hmax; ++j)
            sum[j] = (sum[j - 1] + dp[i][j]) % P;
    }
    return dp[N][0];
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> H[i];
        hmin = min(hmin, H[i]);
        hmax = max(hmax, H[i]);
    }
    if (N % 2 == 0) cout << clc() << endl;
    else {
        ll ans = 0;
        while (hmin >= 0){
            ans = (ans + clc()) % P;
            for (int i = 1; i <= N; ++i)
                H[i]--;
            hmin--;
            hmax--;
        }
        printf("%lld\n", ans);
    }
    

}