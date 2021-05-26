#include<bits/stdc++.h>
using namespace std;
int T, n, m;
const int M = 4e5 + 5;
bool status[M];
vector<int> Got(M);
bool checkWater();
int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
        cout << checkWater() << endl;
    return 0;
}
bool checkWater(){
    cin >> n >> m;
    vector<int> wt(n);
    memset(status, 0, M);
    Got.clear();
    Got.push_back(0);
    status[0] = 0;
    for (int i = 0; i < n; ++i)
        cin >> wt[i];
    int Gbeg = 0, Gend = 1, Gend_float = 1;
    for (int i = 0; i < n; ++i){
        Gbeg = 0;
        Gend = Gend_float;
        while (Gbeg != Gend + 1){
            int tmp = Got[Gbeg] + wt[i];
            if (tmp == m)  return true;
            else if(tmp < m && !status[tmp]){
                status[tmp] = 1;
                Got[++Gend_float] = tmp;
            }
            Gbeg++;
        }
    }
    return false;
}