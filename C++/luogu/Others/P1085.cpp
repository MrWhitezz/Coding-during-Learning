#include<iostream>
using namespace std;

int main()
{
    int a1, a2, b1, b2, c1, c2, d1, d2, e1, e2, f1, f2, g1, g2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2 >> e1 >> e2 >> f1 >> f2 >> g1 >> g2;
    int count = 0;
    int max = 8;
    if (a1 + a2 > max)
    {
        count = 1;
        max = a1 + a2;
    }
    else if (b1 + b2 > max)
    {
        count = 2;
        max = b1 + b2;
    }
    else if (c1 + c2 > max)
    {
        count = 3;
        max = c1 + c2;
    }
    else if (d1 + d2 > max)
    {
        count = 4;
        max = d1 + d2;
    }
    else if (e1 + e2 > max)
    {
        count = 5;
        max = e1 + e2;
    }
    else if (f1 + f2 > max)
    {
        count = 6;
        max = b1 + b2;
    }
    else if (g1 + g2 > max)
    {
        count = 7;
        max = b1 + b2;
    }

    cout << count;
    return 0;
}
