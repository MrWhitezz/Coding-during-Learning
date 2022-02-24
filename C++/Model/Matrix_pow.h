#include<bits/stdc++.h>
using namespace std;
const long long P=1e9+7;
typedef long long ll;
int k,p;
ll read(){
	ll ans=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ans=ans*10+c-48,c=getchar();
	return ans;
}
struct M
{
    ll v[62][62];
    M(){
        memset(v, 0, sizeof(v));
    }
    friend M operator* (M a, M b){
        M c;
        for (int i = 1; i <= k + 1; ++i)
            for (int j = 1; j <= k + 1; ++j)
                for (int l = 1; l <= k + 1; ++l)
                    c.v[i][j] = (c.v[i][j] + a.v[i][l] * b.v[l][j]) % P;
        return c;
    }
    friend M operator^(M a, ll b){
        M ans;
        for (int i = 1; i <= k + 1; ++i)
            ans.v[i][i] = 1;
        for (; b; b >>= 1, a = a * a)
            if (b & 1) ans = ans * a;
        return ans;
    }
};