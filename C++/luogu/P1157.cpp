#include<bits/stdc++.h>
using namespace std;
int n, r;
void dfs(int pos, int rest, bool a[]);
void print_a(bool a[]);
int main()
{
    cin >> n >> r;
    bool a[n];
    for (int i = 0; i < n; i++) a[i] = false;
    dfs(0, r, a);
    return 0;
}
void dfs(int pos, int rest, bool a[])
{
    if (rest == 0){print_a(a); return;}
    if (rest > n - pos) return;

    a[pos] = true;
    dfs(pos + 1, rest - 1, a);
    a[pos] = false;
    dfs(pos + 1, rest, a);
}
void print_a(bool a[])
{
    for (int i = 0; i < n; i++)
        if (a[i])
        {
            if ((i + 1) / 10) cout << " " << i + 1;
            else cout << "  " << i + 1;
        }
    cout << endl;
}
