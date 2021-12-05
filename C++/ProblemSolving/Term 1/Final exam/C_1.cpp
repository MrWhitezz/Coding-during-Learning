#include<bits/stdc++.h>
using namespace std;
long long x, y, z, T1, T2, T3, M;
long long T[3];
bool check(long long a);
void get_chk(int pos, long long sum, bool chk[]);
long long extended_gcd(long long a, long long b, long long &x, long long &y);
int main()
{
    cin >> x >> y >> z;
    T1 = x * y; T[0] = T1;
    T2 = x * z; T[1] = T2;
    T3 = y * z; T[2] = T3;
    M = x * y * z;
/*
    for (long long k = x * y * z - 1; k > 0; k--)
    {
        if (!check(k)){cout << k; break;}
    }
*/
    long long x = 1; y = 0;
    extended_gcd(12, 30, x, y);
    cout << x << endl << y;

    return 0;
}
bool check(long long a)
{
    for (long long i = 0; i <= a / T3; i++)
    {
        long long a1 = a - i * T3;
        for (long long j = 0; j <= a1 / T2; j++)
        {
            long long a2 = a1 - j * T2;
            if (!(a2 % T1)) return true;
        }
    }
    return false;
}
long long extended_gcd(long long a, long long b, long long &x, long long &y)
{
 	   long long r, tmp;
	   if (b==0) {  x = 1;  y = 0;  return a; }
	   r = extended_gcd(b, a % b, x, y);
 	   tmp = x;  x = y;  y = tmp - a / b * y;
      return r;
}

