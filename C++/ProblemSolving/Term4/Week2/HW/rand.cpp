#include<bits/stdc++.h>
using namespace std;
int n = 20, b = 100;
int P = 15;
int main (int argc, char *argv[]){
    srand((unsigned)time(NULL));
    printf("%d %d\n", n, b);
    for(int i = 0; i < n; ++ i){
        cout << rand() % P << " ";
    } 
    cout << endl;
    assert(argc == 2);
    if (strcmp(argv[1], "fast") == 0){
        P = 100;
    }
    else P = 1000;
    for (int i = 0; i < n; ++i){
        cout << rand() % P << " ";
    }
}