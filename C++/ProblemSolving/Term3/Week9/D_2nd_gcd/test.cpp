#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll a[100005];
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else return gcd(b, a % b);
}
ll d;
bool pf;
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        d = gcd(a[1], a[i]);
        if (d == 1)
            printf("-1 ");
        else{
            pf = true;
            for (ll j = 2; j * j <= d; ++j){
                if (d % j == 0){
                    printf("%lld ", d / j);
                    pf = false;
                    break;
                }
            }
            if (pf)
                printf("1 ");
        }
    }

}