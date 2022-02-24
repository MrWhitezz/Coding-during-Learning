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

ll a, b, x, y;
int main(){
   cin >> a >> b;
   gcd_ext(a, b, x, y); 
   x %= b;
   while(x < 0) x += b;
   cout << x << endl;
}