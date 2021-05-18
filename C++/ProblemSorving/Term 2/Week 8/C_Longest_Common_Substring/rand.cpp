#include<bits/stdc++.h>
using namespace std;
void print_str();
int main()
{
    srand((unsigned)time(NULL));
    print_str();
    print_str();
    return 0;
}
void print_str()
{
    int n = rand() % 10;
    for (int i = 0; i < n + 1; ++i)
        cout << (char)(rand() % 6 + 'a');
    cout << endl;
}