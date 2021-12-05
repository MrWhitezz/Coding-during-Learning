#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
ll b[maxn], c[maxn], sum[maxn];
bool is_prime[maxn];
ll prime[maxn], fac[maxn];
ll len_pri, n, k, a, ans;
void init(){
    for (ll i = 0; i < maxn; ++i)
        is_prime[i] = true;
    for (ll i = 2; i * i <= maxn; ++i){
        if (is_prime[i]){
            for (ll j = i + i; j < maxn; j += i){
                is_prime[j] = false;
            }
        }
    }
    len_pri = 0;
    for (ll i = 2; i < maxn; ++i){
        if (is_prime[i])
            prime[len_pri++] = i;
    }
}
ll fast_pow(ll x, ll N){
    ll res = 1;
    ll tmp = x;
    for (; N; N >>= 1, tmp = (tmp * tmp)){ 
        if (tmp >= maxn || tmp < 0)
            return 0;
        if (N & 1)
            res = (res * tmp); 
        if (res >= maxn || res < 0)
            return 0;
    }
    return res;
}

void fac_a(ll i){
    ll pos = 0;
    ll index = 0;
    while (a != 1){
        index = 0;
        while (a % prime[pos] == 0){
            index++;
            a /= prime[pos];
        }
        fac[pos] = index % k;
        pos++;
    }
    // assert(pos <= len_pri);
    ll tmp_b = 1, tmp_c = 1;
    for (ll j = 0; j < pos; ++j){
        tmp_b *= fast_pow(prime[j], fac[j]);
        tmp_c *= fast_pow(prime[j], (k - fac[j]) % k);
        if (tmp_c >= maxn || tmp_c < 0)
            tmp_c = 0;
    }
    b[i] = tmp_b;
    // prllf("b[%d] = %d\n", i, b[i]);
    c[i] = tmp_c;
    // prllf("c[%d] = %d\n", i, c[i]);
}
int main(){
    init();

    cin >> n >> k;
    for (ll i = 0; i < n; ++i){
        cin >> a;
        fac_a(i);
        // prllf("c[%d] = %d\n", i, c[i]);
        ans += sum[c[i]];
        sum[b[i]]++;
    }
    printf("%lld\n", ans);
}