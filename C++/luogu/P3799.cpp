#include<bits/stdc++.h>
using namespace std;
int num(int x, multiset<int> s);
int main()
{
    set<int> Stk1;
    multiset<int> Stk2;
    int n, temp, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        Stk1.insert(temp);
        Stk2.insert(temp);
    }
    for (set<int>::iterator it = Stk1.begin(); it != Stk1.end(); it++)
    {
        for (set<int>:: iterator jt = it; jt != Stk1.end(); jt++)
        {
            if (Stk1.find(*it + *jt) != Stk1.end())
            {
                int a = num(*it,Stk2);
                int b = num(*jt,Stk2);
                int c = num(*it + *jt,Stk2);
                int fac1 = it == jt ? a * (a - 1) / 2 : a * b;
                int fac2 = c * (c - 1) / 2;
                ans += fac1 * fac2;
            }
        }
    }
    cout << ans;
    return 0;
}
int num(int x, multiset<int> s)
{
    int temp = 0;
    for (multiset<int>:: iterator k = s.lower_bound(x); k != s.upper_bound(x); k++)
        temp++;
    return temp;
}
