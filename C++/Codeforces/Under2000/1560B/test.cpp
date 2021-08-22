#include<bits/stdc++.h>
using namespace std;
int main(){
    int T, a, b, c, n;
    cin >> T;
    while (T--){
        cin >> a >> b >> c;
        n = 2 * abs(a - b);
        if (a > n || b > n || c > n) cout << -1 << endl;
        else cout << (c + n / 2 - 1) % n + 1 << endl;
    }
    return 0;
}