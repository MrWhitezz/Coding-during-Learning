#include <bits/stdc++.h>
using namespace std;
#define maxn 30
vector<string> V;
unordered_map<char, int> H;
set<int> num_set;
bool num_occupy[maxn];
int n;
bool dfs(int k, int carry);
bool prune(int t);
bool judge();
int main(){
    cin >> n;
    V.resize(3);
    cin >> V[0] >> V[1] >> V[2];
    assert(V[0].size() == n);
    for (int i = 0; i < 3; ++i)
        reverse(V[i].begin(), V[i].end());

    for (char ch = 'A'; ch < 'A' + n; ++ch){
        H[ch] = n; // non-exit
    }
    for (int i = 0 ; i < n; ++i)
        num_set.insert(i);

    assert(dfs(0, 0) == true);

    for (char ch = 'A'; ch < 'A' + n; ++ch){
        cout << H[ch] << " ";
    }
    
    cout << endl;


}


bool prune(int t){
    for (int i = t; i < n; ++i){
        int A1 = H[V[0][i]], A2 = H[V[1][i]], S = H[V[2][i]];
        if (!(A1 == n || A2 == n || S == n)){
            if (!(((A1 + A2 - S) % n == 0) || ((A1 + A2 - S + 1) % n == 0))){
                return true;
            }
            if (i == n - 1 && (A1 + A2 + 1 - S > n))
                return true;
        }
    }
    return false;
}

bool dfs(int k, int carry){
    int row = k % 3, col = k / 3;
    if (row == 0 && k != 0){
        int col1 = col - 1;
        assert(col1 >= 0);
        int A1 = H[V[0][col1]], A2 = H[V[1][col1]], S = H[V[2][col1]];
        if ((A1 + A2 - S + carry) % n != 0) return false;
        carry = (A1 + A2 - S + carry) / n;
    }
    if (prune(col)) return false;
    

    if (k == 3 * n) return carry == 0;

    if (H[V[row][col]] != n) {
        return dfs(k + 1, carry);
    }
    else{
        for (int i = n - 1; i >= 0; --i){
            if (num_occupy[i] == false){
                num_occupy[i] = true;
                H[V[row][col]] = i;
                if (dfs(k + 1, carry)) return true;
                num_occupy[i] = false;
                H[V[row][col]] = n;
            }
        }
    }
    return false;
}