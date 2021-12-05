#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    unsigned n = rand() % 15, k = rand() % 15;
    if (k <= n)
        cout << n << " " << k;
    else cout << k << " " << n;
    return 0;
}
