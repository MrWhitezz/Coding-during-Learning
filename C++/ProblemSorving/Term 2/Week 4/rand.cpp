#include<iostream>
#include<ctime>
const int MOD = 1e9;
const int T = 1e2;
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    int n = rand() % T + 2, m = rand() % T + 2, k = rand() % 15;
    cout << n << " " << m << " " << k << endl;
    for (int i = 0; i < k; ++i){
        int x = rand() % (n - 1) + 1, y = rand() % (m - 1);
        cout << x << " " << y << endl;
    }

    return 0;
}
