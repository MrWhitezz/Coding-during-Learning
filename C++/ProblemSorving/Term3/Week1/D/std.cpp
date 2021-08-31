//BFS idea, but memory is limited
#include<bits/stdc++.h>
using namespace std;
const int x_max = 1e3;
bitset<x_max + 5> b{0x0};
int main(){
    b[0] = 1;
    int n, q, query_val;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (!b[a[i]]){
            for (int j = 0; j < x_max / a[i]; ++j)
                b |= b << a[i];
        }
    }
    cin >> q;
    
    for (int i = 0; i < q; ++i){
        cin >> query_val;
        if (b[query_val]) cout << "Acesrc!" << endl;
        else cout << "Acesrc?" << endl;
    }

    return 0;
}