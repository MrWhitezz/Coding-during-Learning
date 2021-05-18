#include<iostream>
#include<ctime>
const int MOD = 1e2;
const int T = 2e1;
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    int n = rand() % T;
    cout << n << endl;
    for (int i = 0; i < n; ++i){
        int x = rand() % MOD;
        cout << x << " ";
    }
    return 0;
}

