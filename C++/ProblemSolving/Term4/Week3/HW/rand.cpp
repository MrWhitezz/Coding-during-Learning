#include<bits/stdc++.h>
using namespace std;
int n = 100, b = 50000;
#define PW 1000
#define PC 1000
int main (int argc, char *argv[]){
    srand((unsigned)time(NULL));
    printf("%d %d\n", n, b);
    for(int i = 0; i < n; ++ i){
        cout << rand() % PW << " ";
    } 
    cout << endl;

    for (int i = 0; i < n; ++i){
        cout << rand() % PC << " ";
    }
}