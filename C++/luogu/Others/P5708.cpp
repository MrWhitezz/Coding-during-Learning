#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main()
{
    double a, b, c, p;
    cin >> a >> b >> c;
    p = (a + b + c) / 2;
    double s;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.1lf",s);
    return 0;
}
