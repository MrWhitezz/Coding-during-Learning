#include <bits/stdc++.h>
using namespace std;
#define maxn 30
vector<string> V;
unordered_map<char, int> H;
bool num_occupy[maxn];
int n;
bool judge();
bool dfs(int k, int carry);
int main(){
    cin >> n;
    V.resize(3);
    cin >> V[0] >> V[1] >> V[2];
    assert(V[0].size() == n);

    for (char ch = 'A'; ch < 'A' + n; ++ch){
        H[ch] = n; // non-exit
    }
    assert(dfs(0, 0) == true);

    for (char ch = 'A'; ch < 'A' + n; ++ch){
        cout << H[ch] << " ";
    }
    
    cout << endl;


}

bool dfs(int k, int carry){
    int row = k % 3, col = k / 3;
    if (k == 3 * n) return judge();
    if (k == 3){
        int A1 = H[V[0][0]], A2 = H[V[1][0]], S = H[V[2][0]];
        if (!((A1 + A2 == S) || (A1 + A2 + 1 == S))){
            return false;
        }
    }
    if (row == 0 && k != 0){
        int col1 = col - 1;
        assert(col1 >= 0);
        int A1 = H[V[0][col1]], A2 = H[V[1][col1]], S = H[V[2][col1]];
        if (!((A1 + A2 - S) % n == 0 || (A1 + A2 + 1 - S) % n == 0)){
            return false;
        }
        int this_carry = (A1 + A2 - S + 1) / n;
        if (this_carry != carry) return false;
        if ((A1 + A2 - S) % n == 0) carry = 0;
        else    carry = 1;
    }

    if (H[V[row][col]] != n) {
        return dfs(k + 1, carry);
    }
    else{
        for (int i = 0; i < n; ++i){
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

bool judge(){
    int carry = 0;
    for (int i = n - 1; i >= 0; i--){
        if ((H[V[0][i]] + H[V[1][i]] + carry - H[V[2][i]]) % n != 0){
            return false;
        }
        carry = (H[V[0][i]] + H[V[1][i]] + carry - H[V[2][i]]) / n;
    }
    return carry == 0;
}