#include<iostream>
using namespace std;
int a[9][9];
int p0[81];
bool check (int *a, int p, int v);
bool judge = true;
void place(int *a, int p);
void print(int *a);
int main()
{
    for (int i = 0; i < 81; i++) p0[i] = -1;
    int cont = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
            if (!a[i][j]) p0[cont++] = i * 9 + j;
        }
    }
    place(&a[0][0],p0[0]);
    print (&a[0][0]);

    return 0;
}
bool check (int *a, int p, int v)
{
    int x = p / 9;
    int y = p % 9;
    for (int i = 0; i < 9; i++)
        if (i != x && *(a + i * 9 + y) == v) return false;
    for (int i = 0; i < 9; i++)
        if (i != y && *(a + x * 9 + i) == v) return false;
    int x1 = x / 3;
    int y1 = y / 3;
    for (int i = 3 * x1; i < 3 * x1 + 3; i++)
    {
        for (int j = 3 * y1; j < 3 * y1 + 3; j++)
            if ((i != x || j != y) && *(a + i * 9 + j) == v) return false;
    }
    return true;
}
void place(int *a, int p)
{
    if (p == 81) judge = false;
    if (!judge) return;

    for (int i = 1; i <= 9; i++)
    {
        if (check(a, p, i))
        {
            *(a + p) = i;
                //cout << "a[" << p / 9 << " ][" << p % 9 << "] = " << i << endl;
                //print (a); cout << endl;
            int p1 = 0;
            for (int j = 0; j < 81; j++)
                if (p0[j] > p) {p1 = p0[j]; break;}
            p1 = p1 == 0 ? 81 : p1;
            place (a, p1);
        }
        if (judge)
        {
            for (int j = 0; j < 81; j++)
                if (p0[j] > p) *(a + p0[j]) = 0;
        }

    }
}
void print(int *a)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << *(a + 9 * i + j) << " ";
        cout << endl;
    }
}

