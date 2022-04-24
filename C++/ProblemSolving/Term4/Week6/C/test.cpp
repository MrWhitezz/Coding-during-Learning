#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
#define MASK ((1LL << N) - 1)
vector<set<int>> Edge;
unordered_map<ll, int> fir;
// unordered_map<ll, int> sec;
vector<int> state;
void flip(int x) {
    state[x] = 1 - state[x];
    for (auto y : Edge[x]) {
        state[y] = 1 - state[y];
    }
}
ll state_to_ll() {
    ll ans = 0;
    for (auto it = state.rbegin(); it != state.rend(); it++) {
        ans = (ans << 1) + *it;
    }
    assert(ans <= MASK);
    return ans;
}
int ans = 100;
int main() {
    cin >> N >> M;
    Edge.resize(N + 5);
    int mid = N / 2;
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        Edge[a].insert(b);
        Edge[b].insert(a);
    }

    for (ll i = 0; i < (1LL << mid); i++) {
        ll x = i;
        int pos = 0, cnt = 0;
        state = vector<int>(N + 2, 0);
        while(x > 0) {
            if (x & 1) { 
                assert(pos >= 0 && pos <= mid - 1);
                flip(pos); 
                cnt++;
            }
            x >>= 1;
            pos++;
        }
        ll st = state_to_ll();
        if (st == 0) continue;
        if (fir.find(st) == fir.end()) { fir[st] = cnt; }
        else { fir[st] = min(fir[st], cnt); }
        assert(fir[0] == 0);
    }

    for (ll i = 0; i < (1LL << (N - mid)); ++i){
        ll x = i;
        int pos = mid, cnt = 0;
        state = vector<int>(N + 2, 0);
        while(x > 0) {
            if (x & 1) { 
                assert(pos >= mid && pos <= N - 1);
                flip(pos); 
                cnt++;
            }
            x >>= 1;
            pos++;
        }
        ll st = state_to_ll();
        if (st == MASK) {
            ans = min(ans, cnt);
            // printf("x = %x\n", i);
        }
        else if (fir.find(st ^ MASK) != fir.end()) {
            ans = min(ans, cnt + fir[st ^ MASK]);
            // printf("x << mid = %x, st = %x, st ^ MASK = %x\n", i << mid, st, st ^ MASK);
            
        }
    }
    if (ans == 100) ans = -1;
    cout << ans << endl;
}