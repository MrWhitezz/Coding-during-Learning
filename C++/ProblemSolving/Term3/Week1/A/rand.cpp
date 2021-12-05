#include<bits/stdc++.h>
using namespace std;
const int Size = 20, P = 25000000;
int main (){
    srand((unsigned)time(NULL));
    int n = rand() % Size, m = rand() % (n * (n - 1) / 2);
    int u, v, w;
    cout << n << " " << m << endl;
    for (int i = 0; i < m; ++i){
        u = rand() % n + 1;
        v = rand() % n + 1;
        w = rand() % P + 1;
        printf("%d %d %d \n", u, v, w);
    }
}