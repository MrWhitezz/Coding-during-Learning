#include<bits/stdc++.h>
using namespace std;
// class Solution_Failed {
// public:
//     bool isMatch(string s, string p) {
//         int i = 0, j = 0;
//         for (; i < s.size(); i++){
//             if (j >= p.size()) return false;
//             if (j == p.size() - 1){
//                 if (p[j] == '*'){
//                     if (p[j - 1] == '.' || p[j - 1] == s[i]) continue;
//                     else return false;
//                 }
//                 else if (p[j] == s[i] || p[j] == '.'){
//                     j++;
//                     continue;
//                 }
//                 else return false;
//             }
//             if (s[i] != p[j]){
//                 if (p[j + 1] != '*') return false;
//                 else{
//                     j += 2;
//                     i--;
//                     continue;
//                 }
//             }
//             else{
//                 if (p[j + 1] != '*'){
//                     j++;
//                     continue;
//                 }
//                 else{
//                     int cont = 0;
//                     for (; j < p.size(); j++){
//                         if (j == p.size()){
//                             if (p[j] != s[i] && p[j] != '.') break;
//                             else{

//                             }

//                         }

//                     }
//                 }
//             }        
//         }
        
// };
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size() + 1][p.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int j = 1; j <= p.size(); j++){
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }
        for (int i = 1; i <= s.size(); i++){
            for (int j = 1; j <= p.size(); j++){
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] != '*') dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || '.' == p[j - 2]));
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
int main()
{
    string s1 = "aaa", s2 = "aa";
    Solution s;
    cout << s.isMatch(s1, s2);
    return 0;
}