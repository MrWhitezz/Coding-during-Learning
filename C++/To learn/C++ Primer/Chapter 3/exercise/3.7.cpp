#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s = "this is a string";
   for (char &c : s)
      c = 'X';
   cout << s << endl;
   return 0;
}