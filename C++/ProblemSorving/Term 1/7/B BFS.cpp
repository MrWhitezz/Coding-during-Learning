#include<iostream>
#include<algorithm>
using namespace std;
short check_0(short *a, int);
void test01(short *a, int);
void grow (short *a, int x, int y, int n, int m);
void print (short *a, int n);
int main()
{
    int n;
    cin >> n;
    short a[n][n];
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        cin >> a[i][j];
    //test01(&a[0][0], n);
    //grow (&a[0][0], 3, 3, n, 3);
    //print (&a[0][0], n);
    int distance = 0;
    while (check_0(&a[0][0], n))
    {
        distance ++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == distance)
                    grow(&a[0][0], i, j, n, distance + 1);
            }
        }
    }
    cout << distance;


    return 0;
}
short check_0(short *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (! (*(a + j + i * n))) return true;
    }
    return false;
}
void test01(short *a, int n)
{
    if(check_0(a, n))
        cout << "0 exists";
    else
        cout << "all 1";
}
void grow (short *a, int x, int y, int n, int m)
{
    if (x < n - 1 && *(a + (x + 1) * n + y) == 0) *(a + (x + 1) * n + y) = m;
    if (x > 0 && *(a + (x - 1) * n + y) == 0) *(a + (x - 1) * n + y) = m;
    if (y < n - 1 && *(a + x * n + y + 1) == 0) *(a + x * n + y + 1) = m;
    if (y > 0 && *(a + x * n + y - 1) == 0) *(a + x * n + y - 1) = m;
}
void print (short *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << *(a + i * n + j) << " ";
        cout << endl;
    }
}
