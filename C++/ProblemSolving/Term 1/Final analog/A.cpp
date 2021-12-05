 #include<bits/stdc++.h>
 using namespace std;
 const int ArSize = 20000;
 long long prime[ArSize];
 bool isPrime(long long x);
 void getPrime();
 long long cont = 0;
 long long n;
 bool dfs(long long d, int pri, int w);
 int main()
 {
     getPrime();
     int w;
     cin >> n >> w;
     dfs(1, 0, w);
     cout << cont;
     return 0;
 }
 void getPrime()
 {
     int k = 0;
     for (long long i = 2; i < 210000LL; i++)
         if (isPrime(i)) prime[k++] = i;
 }
bool isPrime(long long x)
{
    for (long long i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}
bool dfs(long long d, int pri, int w)
{
    if (w == 0) {cont++;return true;}
    if ((d * prime[pri] > n) || (w < 0)) return false;
    else
    {
        int k = 0;
        while (d <= n)
        {
            dfs(d, pri + 1, w - k);
            d *= prime[pri];
            k++;
        }
    }
    return true;
}
