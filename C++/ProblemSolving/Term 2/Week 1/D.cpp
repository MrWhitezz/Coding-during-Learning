#include<bits/stdc++.h>
using namespace std;
bool dfs(int pos, double val, double a[]);
void mySwap(double a[], int x, int y);
int main(){
   int T;
   cin >> T;
   for (int i = 0; i < T; i++){
      double a[4];
      for (int j = 0; j < 4; j++)
         cin >> a[j];
      if (dfs(0, a[0], a))
         cout << "true" << endl;
      else
         cout << "false" << endl;
   }

   return 0;
}
bool dfs(int pos, double val, double a[]){
   if (pos == 3){
      if (abs(val - 24) < 0.001) return true;
      else return false;
   }
   // if (pos == 0){
   //    for (int j = 0; j < 4; j++){
   //       mySwap(a, pos, j);
   //       if(dfs(pos + 1, a[0], a)) return true;
   //       mySwap(a, pos, j);
   //    }
   //    return false;
   // }

   double t = a[pos];
   a[pos] = val;
   for (int j = pos; j < 4; j++){
      mySwap(a, pos, j);
      for (int k = pos + 1; k < 4; k++){
         mySwap(a, pos + 1, k);
         double t1 = a[pos], t2 = a[pos + 1];
         if (dfs(pos + 1, t1 + t2, a) || dfs(pos + 1, t1 * t2, a) || dfs(pos + 1, t1 - t2, a) || dfs(pos + 1, t1 / t2, a) || dfs(pos + 1, t2 - t1, a) || dfs(pos + 1, t2 / t1, a))
            return true;
         mySwap(a, pos + 1, k);
      }
      mySwap(a, pos, j);
   }
   a[pos] = t;
   return false;
}
void mySwap(double a[], int x, int y){
   double temp = a[x];
   a[x] = a[y];
   a[y] = temp;
}