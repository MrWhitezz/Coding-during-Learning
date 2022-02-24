#include<bits/stdc++.h>
using namespace std;
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
ll phi_P;
ll fast_pow(ll x, ll N, ll MOD){
    ll res = 1;
    ll tmp = x;
    for (; N; N >>= 1, tmp = (tmp * tmp) % MOD){ 
        if (N & 1)
            res = (res * tmp) % MOD;
    }
    return res;
}

ll solve(ll a, ll b, ll c, ll d){
    ll c_d = fast_pow(c, d, phi_P);
    ll b_cd = fast_pow(b, c_d, P - 1);
    ll a_bcd = fast_pow(a, b_cd, P);
    return a_bcd;
}


ll a, b, c, d;
int T;
int main(){
    phi_P = getphi(P - 1);
    cin >> T;
    while(T--){
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << endl;
    }
}
