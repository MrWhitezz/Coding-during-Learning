#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long n, b;
   cin >> n >> b;
   long long i = 0;
   while ((i * n + 1) % b)
      ++i;
   cout << (i * n + 1) / b;
   return 0;
}