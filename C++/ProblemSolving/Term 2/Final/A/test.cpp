#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int T;
ll n, m;
int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i){
        cin >> n >> m;
        ll valMax = 0;
        pair<ll, ll> course[n]; // first is value, second is time
        for (ll i = 0; i < n; ++i){
            cin >> course[i].first >> course[i].second;
            valMax += course[i].first;
        }
        
        // ll dp[n + 1][valMax + 1];
        // for (ll i = 0; i <= n; ++i)
        //     dp[i][0] = 0;
        // for (ll j = 1; j <= valMax; ++j)
        //     dp[0][j] = 9223372036854775807ll;
        // for (ll i = 1; i <= n; ++i)
        //     for (ll j = 1; j <= valMax; ++j){
        //         dp[i][j] = dp[i - 1][j];
        //         if (j - course[i - 1].first >= 0 && dp[i - 1][j - course[i - 1].first] != 9223372036854775807ll)
        //             dp[i][j] = min(dp[i][j], dp[i - 1][j - course[i - 1].first] + course[i - 1].second);
        //     }
        vector<ll> pre (valMax + 1), cur(valMax + 1);
        for (ll j = 1; j <= valMax; ++j)
            pre[j] = 9223372036854775807ll;
        for (ll i = 1; i <= n; ++i){
            for (ll j = 1; j <= valMax; ++j){
                cur[j] = pre[j];
                if (j - course[i - 1].first >= 0 && pre[j - course[i - 1].first] != 9223372036854775807ll)
                    cur[j] = min(cur[j], pre[j - course[i - 1].first] + course[i - 1].second);
                
            }
            pre.swap(cur);
        }



        for (ll valFinal = valMax; valFinal >= 0; valFinal--){
            if (pre[valFinal] <= m){
                cout << valFinal << endl;
                break;
            }
        }
    }
    return 0; 
}