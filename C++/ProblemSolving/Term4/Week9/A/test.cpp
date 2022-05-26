#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
set<pair<int, int>> S; // <A[i],i>
set<pair<int, int>> S2; // <-A[i],i>
int n, m;
int A[maxn];

int find_nxt(int p) {
    auto it = S.find({A[p], p});
    assert(it != S.end());
    it ++;
    while (it != S.end()) {
        if (it->second > p)
            return it->second;
        it ++;
    }
    return -1;
}

int find_prev(int p) {
    auto it = S2.find({-A[p], p});
    assert(it != S2.end());
    it ++;
    while (it != S2.end()) {
        if (it->second > p)
            return it->second;
        it ++;
    }
    return -1; 
}

int main() {
    cin >> n >>  m;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        S.insert({A[i], i});
        S2.insert({-A[i], i});
    }

    for (int i = 0; i < m; ++i) {
        int T, p;
        cin >> T >> p;
        if (T == 0)
            cout << find_nxt(p) << endl;
        else {
            assert(T == 1);
            cout << find_prev(p) << endl;
        }
    }

}