#include<iostream>
using namespace std;
//此处有一个精度误差的问题,有待解决
int main()
{
/*
    double x;
    cin >> x;
    int integer = (int)x;
    double demical = x - (double)integer;
    int i1, i2, i3;
    double d1;
    i1 = integer % 10;
    i2 = (integer / 10) % 10;
    i3 = (integer / 100) % 10;
    d1 = demical * 10;

    double I1, I2, I3, D1;
    I1 = i1;
    I2 = i2;
    I3 = i3;
    D1 = d1;
    double rev = D1 + I1 / 10 + I2 / 100 + I3 / 1000;
    //cout << rev;
*/

    double t0, t1;
    cin >> t0;
    t1 = t0 - (double)(int)t0;
    cout << t1 << " ";
    double t2;
    t2 = t1 * 10;
    int t3 = t2;
    cout << t2 << " ";
    cout << t3;



    return 0;
}
