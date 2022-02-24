#include<bits/stdc++.h>
using namespace std;
int N, M;
void dye(char *a, int &steps, int x, int y);
int main()
{
    cin >> N >> M;
    char a[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];
    int steps = N * M;

    for (int i = 1; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            dye(&a[0][0], steps, i, j);
    cout << steps;
    return 0;
}
void dye(char *a, int &steps, int x, int y)
{
    int temp = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < M; j++)
            if (*(a + i * M + j) != 'W') temp++;

    for (int i = x; i < y; i++)
        for (int j = 0; j < M; j++)
            if (*(a + i * M + j) != 'B') temp++;

    for (int i = y; i < N; i++)
        for (int j = 0; j < M; j++)
            if (*(a + i * M + j) != 'R') temp++;

    steps = min(steps, temp);
}

