#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int N, x, y, ans;
vector<int> v(25), p(25), status(25);
void dfs(int i, int pre);
int main()
{
    cin >> N;
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
            status[j] = 1;
            dfs(i + 1, j);
            status[j] = 0;
        }
    }
    else if (i == N) {ans++; return;}
    else{
        if (p[i]){
            for (int j = pre + 1; j <= N; ++j){
                if (!status[j]){
                    status[j] = 1;
                    dfs(i + 1, j);
                    status[j] = 0;
                }
            }
        }
        else{
            for (int j = pre - 1; j >= 1; --j){
                if (!status[j]){
                    status[j] = 1;
                    dfs(i + 1, j);
                    status[j] = 0;
                }
            }
        }
    }
}
