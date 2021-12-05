#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int N, x, y, ans, status;
vector<int> v(25), p(25);
void dfs(int i, int pre);
int main()
{
    cin >> N;
    status = (1 << N) - 1;
    for (int i = 1; i <= N; ++i)
        cin >> v[i];
    for (int i = 1; i < N; ++i)
        p[i] = v[i + 1] > v[i];
    dfs(0, 0);
    cout << ans;
}
void dfs(int i, int pre){
    if (i == 0){
        for (int j = 1; j <= N; ++j){
            status ^= 1 << (j - 1);
            dfs(i + 1, j);
            status ^= 1 << (j - 1);
        }
    }
    else if (i == N) {ans++; return;}
    else{
        if (p[i]){
            int tmp = (status & (-(1 << pre))) >> pre;
            while (tmp > 0){
                ++pre;
                if (tmp & 1){
                    status ^= 1 << (pre - 1);
                    dfs(i + 1, pre);
                    status ^= 1 << (pre - 1);
                }
                tmp >>= 1;
            }
        }
        else{
            int tmp = status & ((1 << (pre - 1)) - 1), j = 0;
            while (tmp > 0){
                if (tmp & 1){
                    status ^= 1 << j;
                    dfs(i + 1, j + 1);
                    status ^= 1 << j;
                }
                tmp >>= 1;
                j++;
            }
        }
    }
}
