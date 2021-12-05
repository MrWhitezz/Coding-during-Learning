#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 1e9 + 7;
ll fast_pow(ll x, ll N){
    ll res = 1;
    ll tmp = x;
    for (; N; N >>= 1, tmp = (tmp * tmp) % P){ 
        if (N & 1)
            res = (res * tmp) % P;
    }
    return res;
}
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else return gcd(b, a % b);
}
ll getphi(ll x){
	ll ans=x;
	for(ll i=2;i*i<=x;++i){
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0) x/=i; 
		}
	}
	if(x!=1) ans=ans/x*(x-1);
	return ans;
}
ll n, m;
ll sum = 0, ans;
int main(){
    cin >> n >> m;
    // for (ll i = 0; i < n; ++i){
    //     ll free_choice = gcd(n, i);
    //     sum = (sum + fast_pow(m, free_choice)) % P;
    // }
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum = (sum + fast_pow(m, i) * getphi(n / i)) % P;
            if (n == i * i) continue;
            sum = (sum + fast_pow(m, n / i) * getphi(i)) % P;
        }
    }
    ll inv = fast_pow(n, P - 2);
    ans = sum * inv % P;
    cout << ans;
    return 0;
}