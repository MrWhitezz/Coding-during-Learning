#include<iostream>
using namespace std;
int row[9], col[9], grid[9];
int cont[512];
int Sudo[9][9];
void flip(int x, int y, int z);
int g(int x, int y);
bool dfs(int now);
void printSudo();
int main()
{
    for (int i = 0; i < 9; i++)
        row[i] = col[i] = grid[i] = (1 << 9) - 1;
    for (int i = 0; i < 512; i++)
        for (int j = i; j; j -= j & (-j))
            cont[i]++;

    int start = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> Sudo[i][j];
            if (Sudo[i][j]) flip(i, j, Sudo[i][j]);
            else start++;
        }
    }

    dfs (start);
    printSudo();
	return 0;
}
void flip(int x, int y, int z)
{
    row[x] ^= 1 << (z - 1);
    col[y] ^= 1 << (z - 1);
    grid[g(x, y)] ^= 1 << (z - 1);
}
int g (int x, int y)
{
    return x / 3 * 3 + y / 3;
}
bool dfs(int now)
{
    if (!now) return true;

    int temp = 10, x, y;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (Sudo[i][j]) continue;
            int val = row[i] & col[j] & grid [g(i, j)];
            if (!val) return false;
            if (temp > cont[val])
            {
                temp = cont[val];
                x = i; y = j;
            }
        }
    }
    int val = row[x] & col[y] & grid[g(x, y)];
    for (;val; val -= val & (-val))
    {
        int p = val & (-val);
        int z = cont[p - 1] + 1;
        Sudo[x][y] = z;
        flip (x, y, z);
        if (dfs(now - 1)) return true;
        Sudo[x][y] = 0;
        flip (x, y, z);
    }
    return false;
}
void printSudo()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << Sudo[i][j] << " ";
        cout << endl;
    }
}
