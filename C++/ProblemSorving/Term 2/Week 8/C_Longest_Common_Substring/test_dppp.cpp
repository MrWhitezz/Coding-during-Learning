//Hard
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A, B;
    cin >> A >> B;
    int n = A.size(), m = B.size();
    vector<int> tmp(26);
    int next[A.size() + 1][26];//next[i][] the first pos after i, A[pos - 1] == [] 
    for (int i = 0; i <= A.size(); ++i)
        for (int j = 0; j < 26; ++j)
            next[i][j] = INT_MAX;

    for (int i = 0; i < A.size(); ++i){
        for (int j = tmp[A[i] - 'a']; j <= i; ++j)// the next pos is i + 1, before it next[][] = i + 1
            next[j][A[i] - 'a'] = i + 1;
        
        tmp[A[i] - 'a'] = i + 1;
    }

    int dp[m + 1][m + 1];   //dp[i][j] gives the lowest pos in A of the tail, 
                            //the subsequence is chosen from the first i elems in B, len is j
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 0;
    for (int i = 0; i <= m; ++i)
        for (int j = i + 1; j <= m; ++j)
            dp[i][j] = INT_MAX;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= i; ++j)
            dp[i][j] = dp[i - 1][j - 1] == INT_MAX ? INT_MAX : min(dp[i - 1][j], next[dp[i - 1][j - 1]] [B[i - 1] - 'a']);
    // if dp[i - 1][j - 1] fail, then fail
    // else we can consider whether choose A[j - 1]
    // choose A[j - 1], we want the lowest of dp[i - 1][j - 1] and what after it
    // not choose, we simply get dp[i - 1][j]
    
    for (int i = m; i >= 0; --i)
        if(dp[m][i] != INT_MAX){
            cout << i;
            return 0;
        }
    return 0;
}