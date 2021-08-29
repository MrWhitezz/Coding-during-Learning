// if you want the program going faster, you do more math
// if you want to think less, the program do more math
#include<bits/stdc++.h>
using namespace std;
string solve(){
    int k;
    string n;
    cin >> n >> k;
    while (1){
        set<char> pre;
        for (auto ch : n) pre.insert(ch);
        if (pre.size() <= k) return n;

        pre.clear();
        int ptr = 0;
        for (; ; ptr++){
            pre.insert(n[ptr]);
            if (pre.size() > k){
                if (n[ptr] == '9') 
                    --ptr;
                n[ptr]++;
                for (int i = ptr + 1; i < n.size(); ++i)
                    n[i] = '0';
                break;
            }
        }
    }
}
int main(){
    int T;
    cin >> T;
    while (T--){
        cout << solve() << endl;
    }
    return 0;
}