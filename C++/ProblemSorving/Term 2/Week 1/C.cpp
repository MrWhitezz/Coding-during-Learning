#include<bits/stdc++.h>
using namespace std;
const int M = 362889;
map<int, bool> cod;
int que[M][3]; // [0] for n, [1] for pos, [2] for steps
int target = 123804765;
const int changeId[9][4] = {
   {-1, 1, 3, -1}, {-1, 2, 4, 0}, {-1, -1, 5, 1}, 
   {0, 4, 6, -1}, {1, 5, 7, 3}, {2, -1, 8, 4},
   {3, 7, -1, -1}, {4, 8, -1, 6}, {5, -1, -1, 7}};
int bfs(int n, int p);
void mySwap(char *ch, int a, int b);
int main(){
   int n, p, n0;
   cin >> n;
   n0 = n;
   for (int i = 0; i < 9; i++){
      if ((n0) % 10 == 0){
         p = 9 - 1 - i;
         break;
      }
      n0 /= 10;
   }

   int ans = 0;
   if (n != target)
      ans = bfs(n, p);
   cout << ans;
   return 0;
}
int bfs(int n, int p){
   int head = 0, tail = 1, temp;
   cod.insert(pair<int, bool>(n, true));
   que[head][0] = n, que[head][1] = p, que[head][2] = 0;
   while(head != tail){
      char cur[10];
      sprintf(cur, "%09d", que[head][0]);
      int pos = que[head][1];
      for (int i = 0; i < 4; i++){
         if (changeId[pos][i] != -1){
            int To = changeId[pos][i];
            mySwap(cur, pos, To);
            sscanf(cur, "%d", &temp);
            if (temp == target) return que[head][2] + 1;
            else{
               if (cod.find(temp) == cod.end()){
                  cod.insert(pair<int, bool>(temp, true));
                  que[tail][0] = temp, que[tail][1] = To, que[tail][2] = que[head][2] + 1;
                  tail++;
               }
            }
            mySwap(cur, pos, To);
         }         
      }
      head++;
   }
}
void mySwap(char *ch, int a, int b){
   char temp = ch[a];
   ch[a] = ch[b];
   ch[b] = temp;
}