#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 1e9 + 7;
int n;
ll ans = 0, a, k;
ll fast_pow(ll x, ll N){
    ll res = 1;
    ll tmp = x;
    for (; N; N >>= 1, tmp = (tmp * tmp) % P){ 
        if (N & 1)
            res = (res * tmp) % P;
    }
    return res;
}
inline ll read()
{
    ll x=0; char ch=getchar();
    int cnt = 0;
    while(ch<'0'||ch>'9') { if(ch=='-') ch=getchar(); }
    while(ch>='0'&&ch<='9') { x=((x<<1)+(x<<3)+(ch^48)) % (P - 1); ch=getchar();}
    return x;
}
int main(){
    k = read();
    cin >> n;
    while (n--){
        //scanf("%lld", &a);
        cin >> a;
        ans = (ans + fast_pow(a, k)) % P;
    }
    cout << ans;
}