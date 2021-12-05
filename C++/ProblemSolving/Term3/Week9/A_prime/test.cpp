#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll p;
int T;
bool is_prime(ll x);
int main(){
    cin >> T;
    while (T--){
        cin >> p;
        if (is_prime(p))
            cout << "true\n";
        else
            cout << "false\n";
    }
}
bool is_prime(ll x){
    for (ll i = 2; i * i <= x; ++i){
        if (x % i == 0)
            return false;
    }
    return true;
}