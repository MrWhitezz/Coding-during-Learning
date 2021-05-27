#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int N, x, y;
ll dp[1 << 20][20 + 1];  //dp[i][j] gives for example, i = (1100010) in binary , j = 2
                        // 1 in i shows pos of what has been used, j shows the current pos(tail)
vector<int> v(25), p(25), status(25);
ll swap(int i, int pos);
ll ans;
int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> v[i];
    for (int i = 1; i < N; ++i)
        p[i] = v[i + 1] > v[i];

    for (int i = 0; i < (1 << 20); ++i)
        for (int j = 0; j <= 20; ++j)
            dp[i][j] = -1;

    for (int i = 1; i <= N; ++i)
        ans += swap((1 << N) - 1, i);
    cout << ans;
    return 0;

}
ll swap(int i, int pos){
    if (dp[i][pos] != -1) return dp[i][pos];
    int pre = i - (1 << (pos - 1)), tmp = pre, tmpp = tmp, len = 1;
    if (!pre) return dp[i][pos] = 1;
    dp[i][pos] = 0;
    int poss = 1;
    while (tmpp -= (tmpp & (-tmpp))) ++len;
    while (tmp){
        if (tmp & 1){
            if ((p[len] && pos > poss) || (!p[len] && pos < poss))
                dp[i][pos] += swap(pre, poss);
        }
        ++poss;
        tmp >>= 1;    
    }
    return dp[i][pos];
}
