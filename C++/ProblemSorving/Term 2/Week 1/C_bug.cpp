#include<bits/stdc++.h>
using namespace std;
const int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
const int digit[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int cantor(int a[], int n);
int *decantor(int x, int n);
const int ArSize = 362889;
int cod[ArSize];
int target[9] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
int targetCan;
int bfs(int t);
void move(int i, int t);
void myCopy(int to[], int from[]);
void myPrint(int a[]);
int main(){
   for (int i = 0; i < ArSize; i++)
      cod[i] = 0;
   targetCan = cantor(target, 9);
   int initial;
   cin >> initial;
   int Initial[9];
   for (int i = 0; i < 9; i++){
      Initial[8 - i] = initial % 10;
      initial /= 10;
   }
   cod[cantor(Initial, 9)] = 1;
   
   //cout << "Hello";
   // int *test1 = decantor(81461, 9);
   // myPrint(test1);
   int res = bfs(1);
   cout << res;
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
   cout << "decantor! \n";
   int *res = new int(n);//某次申请内存空间时爆了？？
   
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
int bfs(int t){
   if (cod[targetCan]) return t - 1;
   for (int i = 0; i < ArSize; i++){
      if (cod[i] == t){
         move(i, t + 1);
      }
   }
   return bfs(t + 1);
}
void move(int i, int t){
   cout << "move1!\n";
   cout << "i = " << i << endl;
   int *From = decantor(i, 9);
   cout << "move2!\n";
   int pos0;
   for (int i = 0; i < 9; i++){
      if (From[i] == 0) pos0 = i;
   }
   int To[9];
   if(pos0 / 3 > 0){
      myCopy(To, From);
      int temp = To[pos0];
      To[pos0] = To[pos0 - 3];
      To[pos0 - 3] = temp;
      int toCan = cantor(To, 9);
      if (!cod[toCan]) {myPrint(To); cod[toCan] = t;}
   }
   if(pos0 / 3 < 2){
      myCopy(To, From);
      int temp = To[pos0];
      To[pos0] = To[pos0 + 3];
      To[pos0 + 3] = temp;
      int toCan = cantor(To, 9);
      if (!cod[toCan]) {myPrint(To); cod[toCan] = t;}
   }
   if(pos0 % 3 > 0){
      myCopy(To, From);
      int temp = To[pos0];
      To[pos0] = To[pos0 - 1];
      To[pos0 - 1] = temp;
      int toCan = cantor(To, 9);
      if (!cod[toCan]) {myPrint(To); cod[toCan] = t;}
   }
   if(pos0 % 3 < 2){
      myCopy(To, From);
      int temp = To[pos0];
      To[pos0] = To[pos0 + 1];
      To[pos0 + 1] = temp;
      int toCan = cantor(To, 9);
      if (!cod[toCan]) {myPrint(To); cod[toCan] = t;}
   }
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