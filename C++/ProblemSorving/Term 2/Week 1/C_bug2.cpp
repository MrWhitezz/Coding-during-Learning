#include<bits/stdc++.h>
using namespace std;
const int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
const int digit[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int cantor(int a[], int n);
int *decantor(int x, int n);
int target[9] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
int targetCan;
int bfs(int t, map<int, int> &cod);
void move(int i, int t, map<int, int> &cod);
void myCopy(int to[], int from[]);
void myPrint(int a[]);
int main(){
   map<int, int> cod;
   targetCan = cantor(target, 9);
   int initial;
   cin >> initial;
   int Initial[9];
   for (int i = 0; i < 9; i++){
      Initial[8 - i] = initial % 10;
      initial /= 10;
   }
   cod.insert(pair<int, int>(cantor(Initial, 9), 0));
   int res = bfs(0, cod);
   // int a[] = {0, 2, 3, 1, 8, 4, 7, 6, 5};
   // cout << cantor(a, 9);
   return 0;
}
int cantor(int a[], int n){
   int res = 0;
   for (int i = 0; i < n; i++){
      int cont = 0;
      for (int j = i + 1; j < n; j++){
         if (a[j] < a[i]) cont++;
      }
      res += cont * factorial[n - i - 1];
   }
   return res;
}
int *decantor(int x, int n){
   int *res = new int(n);
   bool used[n];
   for (int i = 0; i < n; i++)
      used[i] = false;

      for (int i = 0; i < n; i++){
         int pos = x / factorial[n - i - 1];
         for (int j = 0; j < n; j++){
            if (!used[j] && pos == 0){
               res[i] = digit[j];
               x %= factorial[n - i - 1];
               used[j] = true;
               break;
            }
            else if (used[j]) continue;
            else {pos--; continue;}
         }
      }
   return res;
}
int bfs(int t, map<int, int> &cod){
   if (cod.find(targetCan) != cod.end()) return t;
   for (map<int, int>::iterator it = cod.begin(); it != cod.end(); it++){
      //cout << it->first << endl;
      if (it -> second == t){
         move(it -> first, t + 1, cod);
      }
   }
   //cout << t << endl;
   return bfs(t + 1, cod);
}
void move(int i, int t, map<int, int> &cod){
   int *From = decantor(i, 9);
   //myPrint(From);
   int pos0;
   for (int j = 0; j < 9; j++){
      if (From[j] == 0) {
         pos0 = j;
         break;
      }
   }
   int To[9];
   if(pos0 / 3 > 0){
      myCopy(To, From);
      int temp = To[pos0];
      To[pos0] = To[pos0 - 3];
      To[pos0 - 3] = temp;
      int toCan = cantor(To, 9);
      if (cod.find(toCan) == cod.end()) {
         myPrint(To);
         cod.insert(pair<int, int>(toCan, t));
      }
         
   }
   if(pos0 / 3 < 2){
      myCopy(To, From);
      int temp = To[pos0];
      To[pos0] = To[pos0 + 3];
      To[pos0 + 3] = temp;
      int toCan = cantor(To, 9);
      if (cod.find(toCan) == cod.end()) {
         myPrint(To);
         cod.insert(pair<int, int>(toCan, t));
      }
   }
   if(pos0 % 3 > 0){
      myCopy(To, From);
      int temp = To[pos0];
      To[pos0] = To[pos0 - 1];
      To[pos0 - 1] = temp;
      int toCan = cantor(To, 9);
      cout << "toCan = " << toCan << endl;
      cout << "t = " << t << endl;
      if (cod.find(toCan) == cod.end()) {
         myPrint(To);
         cout << "Y1" << endl;
         cod[toCan] = t;//某次插入时裂开了？？
         cout << "N" << endl;
      }
   }
   
   if(pos0 % 3 < 2){
      myCopy(To, From);
      int temp = To[pos0];
      To[pos0] = To[pos0 + 1];
      To[pos0 + 1] = temp;
      int toCan = cantor(To, 9);
      if (cod.find(toCan) == cod.end()) {
         myPrint(To);
         cout << "Y" << endl;
         cod.insert(pair<int, int>(toCan, t));
      }
   }
   //delete From;
}
void myCopy(int to[], int from[]){
   for (int i = 0; i < 9; i++)
      to[i] = from[i];
}
void myPrint(int a[]){
   for (int i = 0; i < 9; i++)
      cout << a[i];
   cout << endl;
}