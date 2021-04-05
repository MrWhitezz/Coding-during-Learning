#include<bits/stdc++.h>
using namespace std;
int main()
{
   int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int *e = &arr[10];
   for (int *p = arr; p != e; p++)
      cout << *p << endl;

      return 0;
}