#include <bits/stdc++.h>
using namespace std;
int n, T, cur, pre;
bool is_valid = false;
unordered_map<int, int> mp;
int main(){
    cin >> T;
    while (T--) {
        cin >> n;
        cur = -1, pre = -1;
        mp.clear();
        is_valid = false;
        for (int i = 0; i < n; i++) {
            cin >> cur;
            mp[cur]++;
            if (mp[cur] > 2 || (mp[cur] == 2 && pre != cur)) {
                is_valid = true;
            }
            pre = cur;
        }
        if (is_valid) cout << "YES" << endl;
        else          cout << "NO" << endl;
    }
    

}