#include<iostream>
#include<cmath>
using namespace std;
const int N = 22;
int q[N];
int cont = 0;
static int n, x, y;
void quene(int row);
bool find (int, int);
void dlt (int);
int r (int);
int main()
{
    cin >> n >> x >> y;
    for (int i = 1; i < n + 1; i++)
        q[i] = - n - 1;
    q[x] = y;
    quene (r(x + 1));
    cout << cont;
    return 0;
}
void quene(int row)
{
    if (row == x)
        cont ++;
    else
    {
        for (int i = 1; i < n + 1; i++)
        {
            if (find (row ,i))
            {
                q[row] = i;
                quene(r(row + 1));
                dlt (row);
            }
        }
        dlt (r(row - 1));

    }
}
bool find (int s, int t)
{
    for (int i = 1; i < n + 1; i++)
        if (t == q[i] || abs(s - i) == abs (t - q[i])) return false;
    return true;
}
void dlt (int row)
{
    int i = row;
    while (i != x)
    {
        q[i] = - n - 1;
        i = r((i + 1));
    }
}
int r (int A)
{
    return A % n == 0 ? n : A % n;
}
