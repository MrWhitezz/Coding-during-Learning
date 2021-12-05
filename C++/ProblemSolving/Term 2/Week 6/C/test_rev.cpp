#include<bits/stdc++.h>
using namespace std;
int n, m, ans, pos, send;
int main()
{
    cin >> n >> m;
    vector<int> gift_stack(n);
    unordered_map<int, int> sent;
    for (int i = 0; i < n; ++i)
        cin >> gift_stack[i];
    for (int i = 0; i < m; ++i){
        cin >> send;
        if(sent.find(send) != sent.end()) ans++;
        else{
            while(gift_stack[pos++] != send) sent[gift_stack[pos - 1]] = 0;
            --pos;
            
            ans += 2 * (pos - i) + 1;
        }
    }
    cout << ans;
    return 0;
}