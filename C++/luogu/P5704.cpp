#include<iostream>
using namespace std;

int main()
{
    char ch;
    cin >> ch;
    int a = ch;
    a -= 32;
    cout << (char)a;
    return 0;
}
