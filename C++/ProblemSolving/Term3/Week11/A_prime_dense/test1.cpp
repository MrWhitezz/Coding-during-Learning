#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5 * 1e4; // largest prime
const int N = maxn; // # prime numbers
bool val[maxn];
int prime[N], cnt = 0; // cnt must be init as 0, prime[1] = 2
void init(int n){ // n < maxn
	memset(val, 1, sizeof(val));
	val[1] = 0;
	for (int i = 2; i <= n; i++){
		if (val[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++){
			val[i * prime[j]] = 0;
			if (i % prime[j] == 0) break;
		}
	}
}
int L, R;
const int maxlen = 1e6 + 5;
bool ans[maxlen]; // true for composite
int solve(int l, int r){
    // l -> ans[0], r -> ans[r - l]
    assert(r - l < maxlen);
    memset(ans, 0, sizeof(ans));
    for (int k = 1; k <= cnt; ++k){
        ll comp = l / prime[k] * prime[k];
        while (comp < l) comp += prime[k];
        if (comp == prime[k]) comp += prime[k];
        while (comp <= r) {
            // printf("%d is composite\n", comp);
            assert(comp >= l);
            ans[comp - l] = true;
            comp += prime[k];
        }
    }
    int res = 0;
    for (int i = 0; i <= r - l; ++i){
        if (ans[i] == false)
            ++res;
    }
    return res;
}
int main(){
    init(maxn - 1);
    cin >> L >> R;    
    cout << solve(L, R) << endl;
    // for (int i = 1; i <= cnt; ++i){
    //     printf("prime[%d] = %d\n", i, prime[i]);
    // }
}