#include<bits/stdc++.h>
using namespace std;
#define N 40005
#define SN 205
int pre[N], nxt[N], last[N], P[N], dp[N], pos[SN], cnt[SN];
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> P[i];
        int value = P[i];
        int last_pos = last[value];
        pre[i] = last_pos; // pre position of same val
        nxt[last_pos] = i; // next position of same val
        last[value] = i;
        nxt[i] = n + 1; // don't know next position for i, init as n + 1
    }

    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i < SN; ++i)
        pos[i] = 1;

    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < SN; ++j) {
            if (pre[i] < pos[j])
                cnt[j] ++; // cnt[j] denotes for interval [pos[j], i], how many different vals
            if (cnt[j] > j) {
                assert(cnt[j] == j + 1);
                assert(P[pos[j]] != P[i]);
                cnt[j] = j;
                while (nxt[pos[j]] < i) {
                    pos[j] ++;
                }
                pos[j] ++;
                assert(pos[j] <= i);
            }
            
            dp[i] = min(dp[i], dp[pos[j] - 1] + j * j);
        }
    }

    cout << dp[n] << endl;
}