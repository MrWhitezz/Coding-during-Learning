#include<iostream>
using namespace std;
long long P = 1e9 + 7;
class matrix
{
public:
    long long m11;
    long long m12;
    long long m21;
    long long m22;

    void mul (matrix &B)
    {
        long long a11 = m11, a12 = m12, a21 = m21, a22 = m22;
        long long b11 = B.m11, b12 = B.m12, b21 = B.m21, b22 = B.m22;
        m11 = (a11 * b11 + a12 * b21) % P;
        m21 = (a21 * b11 + a22 * b21) % P;
        m12 = (a11 * b12 + a12 * b22) % P;
        m22 = (a21 * b12 + a22 * b22) % P;
    }

    void print_mtx()
    {
        cout << m11 << " " << m12 << endl;
        cout << m21 << " " << m22 << endl;
        cout << endl;
    }

};
matrix pow(matrix &A, long long n);
int main()
{
    matrix A1;
    A1.m11 = 1; A1.m12 = 1; A1.m21 = 1; A1.m22 = 0;
    long long n;
    cin >> n;
    matrix X = pow (A1, n);
    //X.print_mtx();
    cout << (X.m21 + X.m22) % P << endl;
    return 0;
}
matrix pow(matrix &A, long long n)
{
    if (n == 1) return A;
    if (n % 2 == 0)
    {
        matrix temp = pow(A, n / 2);
        temp.mul(temp);
        return temp;
    }
    else
    {
        matrix temp = pow(A, n / 2);
        temp.mul(temp);
        temp.mul(A);
        return temp;
    }
}
