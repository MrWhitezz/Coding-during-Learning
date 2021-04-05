#include<iostream>
using namespace std;
//这个算法运用了位运算，值得咀嚼
int n, x, y, upperlim;
int cont = 0;
void quene (int row, int ld, int rd, int row_cont);
int main()
{
    cin >> n >> x >> y;
    upperlim = (1 << n) - 1;
    quene (0, 0, 0, 1);
    //quene (r(x + 1));
    cout << cont;
    return 0;
}

void quene (int row, int ld, int rd, int row_cont)
{
    if (row == upperlim)
        cont ++;
    else
    {
        int pos = upperlim & ~ (row | ld | rd);
        if (row_cont == x)
            pos = pos & (1 << (y - 1));
        while (pos)
        {
            int p = pos & (~pos + 1);
            pos -= p;
            quene (row | p, (ld | p) << 1, (rd | p) >> 1, row_cont + 1);
        }
    }
}
