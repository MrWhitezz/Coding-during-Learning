#include<bits/stdc++.h>
using namespace std;
const int ArSize = 71;
int Spr [ArSize][ArSize];
void getSpr();
int main()
{
    getSpr();
    int n;
    cin >> n;
    cout << Spr[n][0];
    return 0;
}
void getSpr()
{
    for (int i = 1; i < ArSize; i++)
        Spr[0][i] = 1;
    for (int i = 1; i < ArSize; i++)
    {
        for (int j = 1; j < ArSize; j++)
        {
            for (int k = j; k <= i - j; k++)
                Spr[i][j] += Spr[i - j][k];
        }
        Spr[i][i] = 1;
        for (int j = 1; j < ArSize; j++)
            Spr[i][0] += Spr[i][j];
    }
}
