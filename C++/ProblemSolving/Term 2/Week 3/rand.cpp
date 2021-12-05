#include<iostream>
#include<ctime>
const int MOD = 200;
const int T = 1e3;
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    unsigned int seed = rand() * 233;
    int n = rand() % MOD + 1, k = rand() % MOD + 1;
    //cout << n << " " << k << endl;
    // for (int i = 0; i < n; ++i)
    //     cout << ((rand() % 2) ? : (rand() % MOD)  - (rand() % MOD)) << " ";
    cout << seed << " " << n << " " << k << " ";
    return 0;
}
