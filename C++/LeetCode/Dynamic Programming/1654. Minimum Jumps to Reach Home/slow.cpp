// This BFS is too slow!
#include<bits/stdc++.h>
using namespace std;
void jump(map<int, int> &bfs, queue<int> &Q, int pos, int steps);
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int> Forbid;
        for (auto it = forbidden.begin(); it != forbidden.end(); ++it)
            Forbid.insert(*it);
        map<int, int> bfs, flag;// flag: 1 means both directions OK, 0 means only backward
        queue<int> Q;
        Q.push(x);
        bfs.insert({x, 0});
        flag.insert({x, 1});
        if (x == 0) return 0;
        while (!Q.empty()){
            if (flag[Q.front()] == 1){
                if (Forbid.find(Q.front() + b) == Forbid.end() && bfs.find(Q.front() + b) == bfs.end()){
                    jump(bfs, Q, Q.front() + b, bfs[Q.front()] + 1);
                    flag[Q.front() + b] = 0;
                }
            }
            if (Q.front() - a >= 0 && Forbid.find(Q.front() - a) == Forbid.end() && bfs.find(Q.front() - a) == bfs.end()){
                jump(bfs, Q, Q.front() - a, bfs[Q.front()] + 1);
                flag[Q.front() - a] = 1;
                if (Q.front() - a == 0) return bfs[Q.front()] + 1;
            }     
            Q.pop();
        }
        return -1;
    }
};
void jump(map<int, int> &bfs, queue<int> &Q, int pos, int steps){
    bfs[pos] = steps;
    Q.push(pos);
}