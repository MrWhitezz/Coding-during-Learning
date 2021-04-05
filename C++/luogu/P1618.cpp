#include<bits/stdc++.h>
using namespace std;
int A, B, C;
bool check[10];
bool judge(int a, int b, int c);
void reduce (int A, int B, int C);
int main()
{
    cin >> A >> B >> C;
    reduce(A, B, C);
    bool ext = false;
    for (int i = 1; C * i < 1000; i++)
    {
        if (judge(i * A, i * B, i * C))
        {
            cout << i * A << " " << i * B << " " << i * C << endl;
            ext = true;
        }
    }
    if (!ext) cout << "No!!!";
    return 0;
}
bool judge(int a, int b, int c)
{
    for (int i = 0; i < 10; i++)
        check[i] = false;
    check[0] = true;
    if (check[a % 10]) return false; else check[a % 10] = true;
    if (check[a / 10 % 10]) return false; else check[a / 10 % 10] = true;
    if (check[a / 100]) return false; else check[a / 100] = true;
    if (check[b % 10]) return false; else check[b % 10] = true;
    if (check[b / 10 % 10]) return false; else check[b / 10 % 10] = true;
    if (check[b / 100]) return false; else check[b / 100] = true;
    if (check[c % 10]) return false; else check[c % 10] = true;
    if (check[c / 10 % 10]) return false; else check[c / 10 % 10] = true;
    if (check[c / 100]) return false; else check[c / 100] = true;
    return true;
}
void reduce (int A, int B, int C)
{
    int gcd = 1;
    for (int i = 1; i <= A; i++)
        if(A % i == 0 && B % i == 0 && C % i == 0) gcd = i;
    A /= gcd;
    B /= gcd;
    C /= gcd;
}
