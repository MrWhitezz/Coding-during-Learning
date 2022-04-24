#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 200005
#define maxa ((1 << 20) + 5)
#define MASK ((1 << 20)  - 1)
int a[maxn];
ll cnt[maxa];
int n;
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        int g = (~a[i]) & MASK;
        // printf("a[%d] = %d, g = %d\n", i, a[i], g);
        for (int j = g; j != 0; j = (j - 1) & g){
            ans += cnt[j]; 
            // if (cnt[j]) printf("%d & %d = 0\n", a[i], j);
        }
        ans += cnt[0];
    }
    cout << ans << endl;
    
}