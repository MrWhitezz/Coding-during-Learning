#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x);
int cont, sum, n, k;
void dfs(int pos, int rest, int a[]);
int main()
{
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    dfs(0, k, a);
    cout << cont;

    return 0;
}
bool isPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}
void dfs(int pos, int rest, int a[])
{
    if (rest == 0)
    {
        if (isPrime(sum)) cont++;
        return;
    }
    if (n - pos < rest) return;
    dfs(pos + 1, rest, a);
    sum += a[pos];
    dfs(pos + 1, rest - 1, a);
    sum -= a[pos];
}
