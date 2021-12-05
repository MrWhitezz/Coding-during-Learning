//0 points, Tooooooo slow
#include<bits/stdc++.h>
using namespace std;
int T, n, m;
bool dp[4002][400002];
unordered_map<string, bool> check;
int wt[4002];
bool checkWater(int x, int y);
int main()
{
    cin >> T;
    // for (int i = 0; i <= 4000; ++i)
    //     dp[i][0] = 1;
    // for (int i = 1; i <= 400000; ++i)
    //     dp[0][i] = 0;
    
    for (int i = 0; i < T; ++i){
        check.clear();
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> wt[i];
        cout << checkWater(n ,m) << endl;
    }
    return 0;
}
bool checkWater(int x, int y){
    if (y == 0) return 1;
    if (x == 0) return 0;
    if (check.find(to_string(x) + to_string(y)) != check.end()) return dp[x][y];
        dp[x][y] = wt[x - 1] > y ? checkWater(x - 1, y) : checkWater(x - 1, y) | checkWater(x - 1, y - wt[x - 1]);
        //dp[i][j] = wt[i - 1] > j ? dp[i - 1][j] : dp[i - 1][j] | dp[i - 1][j - wt[i - 1]];
    check[to_string(x) + to_string(y)] = 0;
    return dp[x][y];
}