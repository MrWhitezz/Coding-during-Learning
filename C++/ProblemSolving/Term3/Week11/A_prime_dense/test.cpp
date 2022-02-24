#include<bits/stdc++.h>
using namespace std;
int L, R;
bool is_prime(int x) {
    // omit 2
    if (x == 1) return false;
    for (int i = 3, prod = 9; prod <= x; i += 2){
        if (x % i == 0)
            return false;
        prod += 2 * i + 1;
    }
    // printf("%d is prime\n", x);
    return true;
}
int solve(int l, int r){
    int beg = l & 1 ? l : l + 1;
    int ans = 0;
    while (beg <= r){
        if (is_prime(beg))
            ans++;
        beg += 2;
    }
    if (l == 2) ans++;
    return ans;

}
int main(){
    cin >> L >> R;
    cout << solve(L, R) << endl;
}