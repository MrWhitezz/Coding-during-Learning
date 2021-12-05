#include<bits/stdc++.h>
using namespace std;
unsigned int f(std::string s, unsigned int base, unsigned int mod) {
    unsigned int rt = 0;
    for (auto i = 0; i < s.size(); i++) 
        rt = ((unsigned long long)rt * base + s[i] - 'a') % mod;
    return rt;
}
int base, mod, k;
int main()
{
    cin >> base >> mod >> k;
    queue<string> q;
    map<int, string> H;
    q.push("");
    while (H.find(k) == H.end()){
        string tmp = q.front();
        for (int i = 0; i < 26; ++i){
            string tmp_i = tmp + (char)('a' + i);
            int tmp_hash = f(tmp_i, base, mod);
            if (H.find(tmp_hash) == H.end()){
                H.insert({tmp_hash, tmp_i});
                q.push(tmp_i);
            }      
        }
        q.pop();
    }
    cout << H[k];
    // if (f(H[k], base, mod) == k) cout << "true";
    // else cout << "false" ;
    return 0;
}