#include<bits/stdc++.h>
using namespace std;
bitset<400005> b;
int T, n, m, wt;
bool checkWater();
int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
        cout << checkWater() << endl;
    return 0;
}
bool checkWater(){
    b = 0x1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> wt;
        b |= b << wt;
    }
    return b[m];
}