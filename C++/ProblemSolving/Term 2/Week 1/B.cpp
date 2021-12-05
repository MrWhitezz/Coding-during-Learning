#include<bits/stdc++.h>
using namespace std;
int a, b, c, k;
bool check(int *o);
int bfs(int *o, int t);
void dumpFrom(int *o, int i, int j, int t);
void dumpTo(int *o, int i, int j, int t);
int main()
{
   cin >> a >> b >> c >> k;
   int cod[b + 1][c + 1];
   for (int i = 0; i <= b; i++)
      for (int j = 0; j <= c; j++)
         cod[i][j] = 0;
   cod[0][0] = 1;
   int res = bfs(&cod[0][0], 1);
   if (res || a == k){
      cout << "yes\n" << (a == k ? 0 : res);
   }
   else
      cout << "no";
   return 0;
}
bool check(int *o){
   if (k <= b){
      for (int i = 0; i <= c; i++)
         if (*(o + k * (c + 1) + i))
            return true;
   }
   if (k <= c){
      for (int i = 0; i <= b; i++)
         if (*(o + i * (c + 1) + k))
            return true;
   }
   int i = b, j = a - k - b;
   if (b >= a - k) {i = a - k; j = 0;}
   else if (c >= a - k){i = 0; j = a - k;}
   else{i = b; j = a - k - b;}

   while (j >= 0 && j <= c && i >= 0 && i <= b){
      if (*(o + i * (c + 1) + j))
         return true;
      if (b >= a - k || c < a - k){i--; j++;}
      else{i++; j--;}
   }
   return false;
}
void dumpFrom(int *o, int i, int j, int t){
   dumpTo(o, 0, j, t);
   dumpTo(o, 0, i + j, t);
   dumpTo(o, i + j - c, c, t);
   dumpTo(o, i, 0, t);
   dumpTo(o, i + j, 0, t);
   dumpTo(o, b, i + j - b, t);
   dumpTo(o, b, j, t);
   dumpTo(o, a - j, j, t);
   dumpTo(o, i, c, t);
   dumpTo(o, i, a - i, t);
}
void dumpTo(int *o, int i, int j, int t){
   if (i >= 0 && i <= b && j >= 0 && j <= c && i + j <= a && 
   *(o + i * (c + 1) + j) == 0)
      *(o + i * (c + 1) + j) = t;
}
int bfs(int *o, int t){
   bool flag = 0;
   for (int i = 0; i <= b; i++){
      for (int j = 0; j <= c; j++){
         if (*(o + i * (c + 1) + j) == t){
            flag = 1;
            dumpFrom(o, i, j, t + 1);
         }
      }
   }
   if (check(o)) return t;
   else if (flag) return bfs(o, t + 1);
   else return 0;
}