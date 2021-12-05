// 本题的思路是先从m中选k个，然后将k个数放在n个位置上（都放上，相邻不重复）
// 可以考虑从{1, 2, 3... n} 到 {1, 2, 3...n }构造满射，但相邻不重复
// 未来得及实现
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int ArSize = 30;
const ll MOD = 1000000007;
int T;
ll dp[ArSize][ArSize];
ll get_comb(ll n, ll m);
ll get_power(ll a, ll n);

int main()
{
    ll n, m, k;
    cin >> T;
    while (T--){
        cin >> n >> m >> k;
        if(n <= 10){
            int a[n];
            for (int i = 0; i < n; ++i){

            }

        }



        if (k == 1 && n == 1)
            cout << m << endl;
        else if ((k == 1 && n > 1) || k > m || k == 0)
            cout << 0 << endl;
        else if (m == k)
            cout << k *((get_power(k - 1, n - 1) - (k - 1) * get_power(k - 2, n - 1) % MOD) % MOD) << endl;
        else
            cout << get_comb(m, k) * k % MOD *((get_power(k - 1, n - 1) - (k - 1) * get_power(k - 2, n - 1) % MOD) % MOD) << endl;
    }


   return 0;
}
ll get_power(ll a, ll n){
    if (n == 0) return 1;
    if (n == 1) return a;
    ll m = n / 2;
    ll tmp = get_power(a, m);
    if (n & 1) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}
ll get_comb(ll n, ll m){
    for (int i = 1; i < ArSize; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
   }
      
    for (int i = 2; i < ArSize; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
   return dp[n][m];
}