#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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
ll look(ll n);
int main(){
    ll N;
    cin >> N;
    cout << look(N + 1);

}
ll look(ll n){
    if (n == 1) return 1;
    if (n == 2) return 3;
    ll pre = look(n - 1);
    // for (ll i = 2; i < n; ++i){
    //     if (gcd(i - 1, n - 1) == 1) pre += 2;
    // }
    pre += 2 * getphi(n - 1);
    return pre;
}
