#include<bits/stdc++.h>
using namespace std;
void print_str(int n);
int main()
{
    srand((unsigned)time(NULL));
    int n = rand() % 10 + 1, m = rand() % 20 + 10;
    cout << n << " "<< m << endl;
    print_str(n);
    print_str(n);
    print_str(n);
    print_str(n);
    return 0;
}
void print_str(int n)
{
    for (int i = 0; i < n; ++i)
        cout << (rand() % 15) << " ";
    cout << endl;
}