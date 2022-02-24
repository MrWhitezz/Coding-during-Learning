#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(int pos, bool check[], int a[]);
void print_a(int a[]);
int main()
{
    cin >> n;
    bool check[n];
    int a[n];
    for (int i = 0; i < n; i++)
        check[i] = false;
    dfs(0, check, a);
    return 0;
}
void dfs(int pos, bool check[], int a[])
{
    if (pos == n) print_a(a);
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            a[pos] = i;
            dfs(pos + 1, check, a);
            check[i] = false;
        }
    }
}
void print_a(int a[])
{
    for (int i = 0; i < n; i++)
        cout << "    " << a[i] + 1;
    cout << endl;
}
