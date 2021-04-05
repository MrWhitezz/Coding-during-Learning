#include <bits/stdc++.h>
using namespace std;
int count_calls(int n)
{
   static int ctr = 0; // ?
   ctr ++;
   return ctr;
}
int main()
{
   for (int i = 0; i != 10; ++i){
      cout << count_calls(i) << endl;
   }
   // static int i = 0;
   // static int i = 5;
   // cout << i << endl;
   return 0;
}