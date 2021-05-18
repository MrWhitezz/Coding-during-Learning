// This is learned from the most popular Python ans
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int ArSize = max(*max_element(forbidden.begin(), forbidden.end()), x) + a + b + 1;
        // This bound needs to be proved
        vector<int> Jumps(ArSize, INT_MAX);
        for (auto it = forbidden.begin(); it != forbidden.end(); ++it)
            Jumps[*it] = -1;
        queue<int> Q;
        if (x == 0) return 0;
        Q.push(0);
        Jumps[0] = 0;
        while (!Q.empty()){
            int pos = Q.front();
            if (pos + a < ArSize && Jumps[pos + a] > Jumps[pos] + 1){
                Jumps[pos + a] = Jumps[pos] + 1;
                Q.push(pos + a);
            }  
            if (pos - b > 0 && Jumps[pos - b] > Jumps[pos] + 1){
                Jumps[pos - b] = Jumps[pos] + 1;
                if (pos - b + a < ArSize && Jumps[pos - b + a] > Jumps[pos] + 2){
                    Jumps[pos - b + a] = Jumps[pos] + 2;
                    Q.push(pos - b + a);
                }
            }
            Q.pop();
        }
        return Jumps[x] == INT_MAX ? -1 : Jumps[x];
    }
};