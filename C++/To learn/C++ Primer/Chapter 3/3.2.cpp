#include<bits/stdc++.h>
using namespace std;
int main()
{
   // string line;
   // while (getline(cin, line))
   //    cout << line << endl;
   // cout << line << endl;

   // string s1, s2;
   // cin >> s1;
   // getline(cin, s2);
   // cout << s1 << endl;
   // cout << s2 << endl;

   // char ch = 'a';
   // cout << (char)toupper(ch);

   string str("some string");
   for (auto c : str)
      cout << c << endl;

   string s("Hello World!!!");
   decltype(s.size()) punct_cnt = 0;
   for (auto c : s)
      if (ispunct(c))
         ++punct_cnt;
   cout << punct_cnt << " punctuation characters in " << s << endl;

   for (auto &c : s)
      c = toupper(c);
   cout << s << endl;

   return 0;
}