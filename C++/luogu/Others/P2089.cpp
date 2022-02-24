#include<bits/stdc++.h>
using namespace std;
void dfs_cont(int pos, int ing);
void dfs_print(int pos, int ing);
int a[10];
int cont = 0;
void print_a();
int main()
{
    int n;
    cin >> n;
    dfs_cont(0, n);
    cout << cont << endl;
    dfs_print(0, n);

    return 0;
}
void print_a()
{
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
}
void dfs_print(int pos, int ing)
{
    if (pos == 10 && ing == 0) print_a();
    if (ing < 10 - pos || ing > 3 *(10 - pos)) return;
    for (int i = 1; i <= 3; i++)
    {
        a[pos] = i;
        dfs_print(pos + 1, ing - i);
    }
}
void dfs_cont(int pos, int ing)
{
    if (pos == 10 && ing == 0) cont++;
    if (ing < 10 - pos || ing > 3 *(10 - pos)) return;
    for (int i = 1; i <= 3; i++)
    {
        //a[pos] = i;
        dfs_cont(pos + 1, ing - i);
    }
}
