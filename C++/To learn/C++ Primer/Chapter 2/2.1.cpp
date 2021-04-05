#include<bits/stdc++.h>
using namespace std;
int reused = 42;
int main()
{
   // for (unsigned i = 10; i >= 0; i--)
   //    cout << i << endl;

   // cout << "a really, really long string literal "
   //         "that spans two lines " << endl;

   // long double ld = 3.11415926;
   // int a{ld}, b = {ld};
   // int c{ld}, d = ld;


   // int month = 09, day = 07;//wrong 09
   // cout << month << endl
   //      << day << endl;

   // int reused = 0;
   // cout << reused << endl;
   // cout << ::reused << endl;

   // int *p1 = nullptr;
   // int *p2 = NULL;
   // int *p3 = 0;
   // int *&r = p1;

   // int i = 42;
   // int &r1 = i;
   // const int &r2 = i;
   // r1 = 0;
   // cout << r1 << endl
   //      << r2 << endl;

   const int i = 42;
   cout << i << endl;
   auto p = &i;
   cout << i << endl;

   return 0;
}