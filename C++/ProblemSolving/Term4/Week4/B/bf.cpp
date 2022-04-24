#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<ll, ll>> pt(1005);
int N;
ll ans = 0;

int main(){
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> pt[i].first >> pt[i].second;
    }
    int cnt_same = 0;
    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){
            ll dx1 = pt[i].first - pt[j].first;
            ll dy1 = pt[i].second - pt[j].second;
            if (dx1 == 0 && dy1 == 0) {++cnt_same; continue;}
            ll num = 0;
            for (int k = 0; k < N; ++k){
                ll dx2 = pt[k].first - pt[i].first;
                ll dy2 = pt[k].second - pt[i].second;
                if (dx1 * dy2 == dx2 * dy1) num++;
            }            
            ans = max(ans, num);
        }
    }
    if (cnt_same == (N * (N - 1) / 2)) {
        cout << N << endl;
        return 0;
    }

    cout << ans << endl;

}