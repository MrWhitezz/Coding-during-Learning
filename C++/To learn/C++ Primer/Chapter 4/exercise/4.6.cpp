#include<bits/stdc++.h>
using namespace std;
int main()
{
   int x;
   while (cin >> x){
      if (x & 1) //以后判断奇偶再也不用模2啦
         cout << x << " is an odd number" << endl;
      else 
         cout << x << " is an even number" << endl;

   }
   return 0;
}