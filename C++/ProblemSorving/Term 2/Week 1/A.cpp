#include<bits/stdc++.h>
using namespace std;
int getDegree(int a[], int n);
int main()
{
   int m, n;
   cin >> m >> n;
   int a[m], b[n];
   for (int i = 0; i < m; i++)
      cin >> a[i];
   for (int i = 0; i < n; i++)
      cin >> b[i];
   int d1 = getDegree(a, m), d2 = getDegree(b, n);
   cout << ((d1 < d2) ? "Yes" : "No") << endl;
   cout << ((d1 <= d2) ? "Yes" : "No") << endl;
   cout << ((d1 == d2) ? "Yes" : "No") << endl;
   cout << ((d1 >= d2) ? "Yes" : "No") << endl;
   cout << ((d1 > d2) ? "Yes" : "No") << endl;
   return 0;
}
int getDegree(int a[], int n)
{
   for (int i = n; i > 0; i--){
      if (a[i - 1])
         return i;
   }
}