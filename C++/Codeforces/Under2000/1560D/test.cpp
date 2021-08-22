#include<bits/stdc++.h>
using namespace std;
int solve(string s, string t);
int main(){
    long long T, tmp = 1;
    int ans = 0;
    string s;
    cin >> T;
    vector<string> ts(1, "1");
    for (long long i = 1; i <= 62; ++i){
        tmp *= 2;
        ts.push_back(to_string(tmp));

    }
    while (T--){
        cin >> s;
        ans = 1000;
        for (auto t : ts){
            ans = min(ans, solve(s, t));
        }
        cout << ans << endl;

    }
    return 0;
}
int solve(string s, string t){
    int sp = 0, tp = 0, taken = 0;
    while (sp < s.size() && tp < t.size()){
        if (s[sp] == t[tp]){
            ++taken;
            ++tp;
        }
        ++sp;
    }
    return s.size() + t.size() - 2 * taken;
}
