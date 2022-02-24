#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    double t;
    int n;
    cin >> t >> n;
    double ave = t / n;
    int cup = 2 * n;

    printf("%.3lf\n", ave);
    printf("%d", cup);
    return 0;
}
