#include<bits/stdc++.h>
using namespace std;
int n, k;
int cont = 0;
void dfs(int pos, int rest);
int main()
{
    cin >> n >> k;
    dfs(1, k);
    cout << cont;
    return 0;
}
void dfs(int pos, int rest)
{
    if (rest < 0) return;
    if (pos == n + 1) {cont++; return;}
    dfs(pos + 1, rest + 1);
    dfs(pos + 1, rest - 1);
}
