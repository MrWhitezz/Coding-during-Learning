#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<ll> A, B;
vector<ll> pre, cur;
int main(){
    cin >> m >> n;
    A.resize(n);
    B.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> B[i];
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // how to prove this sorted property?
    cur = vector<ll>(m + 5, 0x3f3f3f3f3f3f3f3f);
    pre = vector<ll>(m + 5, 0);

    for(int i = 1; i <= n; ++i){
        cur = vector<ll>(m + 5, 0x3f3f3f3f3f3f3f3f);
        for(int j = 1; j <= m; ++j){
            if (i <= j){
                cur[j] = min(cur[j], pre[j - 1] + abs(A[i - 1] - B[j - 1]));
                if (i <= j + 1){
                    cur[j] = min(cur[j], cur[j - 1]);
                }
            }
        }
        cur.swap(pre);
    }
    cout << pre[m] << endl;
}