#include<bits/stdc++.h>
const int x_max = 1e9;
using namespace std;
int main(){
    int n, tmp, q, q_val;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> d(a[0] + 5, INT_MAX);
    d[0] = 0;
    priority_queue<int, vector<int>, greater<int>> Q;
    Q.push(0);
    while (!Q.empty()){
        tmp = Q.top();
        Q.pop();
        for (int i = 1; i < n; ++i){
            int reach = tmp + a[i];
            int p = (reach) % a[0];
            if (reach < x_max && reach < d[p]) {
                d[p] = reach;
                Q.push(reach);
            }
        }
    }

    cin >> q;
    while (q--){
        cin >> q_val;
        if (q_val >= d[q_val % a[0]]) cout << "Acesrc!" << endl;
        else cout << "Acesrc?" << endl;
    }
    

    return 0;
}