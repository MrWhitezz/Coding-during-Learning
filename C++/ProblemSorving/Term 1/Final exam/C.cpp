//�����ҷ����� >=xyz���������Ի��
//Ȼ��ʣ�´�xyz - 1��ʼö��
//ÿ���ж�ʱ�ȿ�����ȡ���ٸ� T3 �ʽ���ʽ����ͬʱmod x Ȼ���ſ��Դ���ŷ����
//�� (T3 mod x) * k �� (a mod x) ���� x ͬ�࣬���k
//�����ٿ���T1, T2 �����Ƶķ��������
//������δ��ȫ�����ŷ��һЩ���̣�����˵����һЩbug
#include<bits/stdc++.h>
using namespace std;
long long x, y, z, T1, T2, T3, r1, r2;
long long gcd(long long m, long long n);
long long extended_gcd(long long a, long long b, long long &x, long long &y);
bool check(long long a);
int main()
{
    cin >> x >> y >> z;
    T1 = x * y;
    T2 = x * z;
    T3 = y * z;

    r1 = y * z % x;
    r2 = z % y;
    for (long long k = x * y * z - 1; k > 0; k--)
    {
        if (!check(k)){cout << k; break;}
    }

    return y;
}
bool check(long long a)
{
    long long r1_a = a % x;
    long long d1 = -1, d2 = -1;
    if (r1_a % gcd(r1, x) != 0) return false;
    long long m = 1, n = 0;
    extended_gcd(r1, x, m, n);
    m *= (r1_a / gcd(r1, x));
    m %= x;
    long long a2 = (a - m * T3) / x;
    if (a2 < 0) return false;
    /*
    for (long long i = 0; i * T3 <= a; i++)
        if (i * r1 % x == r1_a)
        {
            d1 = i;
            break;
        }

    if (d1 == -1) return false;
    */
    long long r2_a = a2 % y;
    if (r2_a % gcd(r2, y) != 0) return false;
    m = 1; n = 0;
    extended_gcd(r2, y, m, n);
    m *= (r2_a / gcd(r2, y));
    m %= y;
    /*
    for (long long i = 0; i * z <= a2; i++)
        if (i * r2 % y == r2_a)
        {
            d2 = i;
            break;
        }
    if (d2 == -1) return false;
    */
    if (a2 - m * z < 0) return false;
    return true;
}
long long gcd(long long m, long long n)
{
    if (n == 0) return m;
    else return gcd (n, m % n);
}
long long extended_gcd(long long a, long long b, long long &x, long long &y)
{
 	   long long r, tmp;
	   if (b==0) {  x = 1;  y = 0;  return a; }
	   r = extended_gcd(b, a % b, x, y);
 	   tmp = x;  x = y;  y = tmp - a / b * y;
      return r;
}
