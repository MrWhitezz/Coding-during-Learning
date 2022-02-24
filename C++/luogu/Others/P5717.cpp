#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] + a[1] <= a[2])
        cout << "Not triangle";
    else
    {
        int s1 = a[0] * a[0];
        int s2 = a[1] * a[1];
        int s3 = a[2] * a[2];
        if (s1 + s2 == s3)
        {
            cout << "Right triangle";
            if (a[0] == a[1])
                cout << "\nIsosceles triangle";
        }

        else if (s1 + s2 > s3)
        {
            cout << "Acute triangle";
            if (a[0] == a[1] || a[1] == a[2])
                cout << "\nIsosceles triangle";
            if (a[0] == a[1] && a[1] == a[2])
                cout << "\nEquilateral triangle";
        }

        else
        {
            cout << "Obtuse triangle";
            if (a[0] == a[1])
                cout << "\nIsosceles triangle";
        }
    }
    return 0;
}
