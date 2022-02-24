using ll = long long;
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

#define P  1000000007
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

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd_ext(ll a, ll b, ll &x, ll &y){
    if (b == 0){
        x = 1; y = 0;
        return a;
    }
    else{
        ll ans = gcd_ext(b, a % b, x, y);
        ll x0 = x, y0 = y, q = a / b;
        x = y0;
        y = x0 - y0 * q;
        assert(x * a + y * b == ans);
        return ans;
    }
}