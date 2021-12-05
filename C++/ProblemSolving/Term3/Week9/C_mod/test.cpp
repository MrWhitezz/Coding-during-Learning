#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b;
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

ll fast_pow(ll x, ll N){
    ll res = 1;
    ll tmp = x;
    for (; N; N >>= 1, tmp = (tmp * tmp) % b){ 
        if (N & 1)
            res = (res * tmp) % b;
    }
    return res;
}

int main(){
    cin >> a >> b;
    ll phi = getphi(b);
    ll ans = fast_pow(a, phi - 1);
    cout << ans;

}