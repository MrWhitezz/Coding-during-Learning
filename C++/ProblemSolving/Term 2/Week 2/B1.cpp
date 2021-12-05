#include<bits/stdc++.h>
using namespace std;
long long extended_gcd(long long a, long long b, long long &x, long long &y);
int main()
{
   long long n, b, c, d;
   cin >> n >> b;
   extended_gcd(n, b, d, c);
   d %= b;
   if (d > 0) d -= b;
   cout << (((-d) * n + 1) / b);
   	long long a,b,m,ans=1;
	// cin>>b>>a;
	// m=b,b-=2;
	// while(b)
	// {
	// 	if(b&1)
	// 	ans=ans*a%m;
	// 	a=a*a%m;
	// 	b>>=1;
	// }
   return 0;
}
long long extended_gcd(long long a, long long b, long long &x, long long &y){
   long long r, temp;
   if (b == 0) {x = 1; y = 0; return a;}
   r = extended_gcd(b, a % b, x, y);
   temp = x;
   x = y;
   y = temp - a / b * y;

   return r;
}