#include<bits/stdc++.h>
using namespace std;
vector<int> bitsnum;
int n, T, tmp, reach0, reach1;
int main(){
    cin >> T;
    while (T--){
        cin >> n;
        bitsnum = vector<int> (n, INT_MAX);
        deque<int> Q;
        Q.push_back(1);
        bitsnum[1] = 1;
        while (bitsnum[0] == INT_MAX){
            tmp = Q.front();
            Q.pop_front();
            //printf("bitsnum[%d] = %d\n", tmp, bitsnum[tmp]);
            reach0 = tmp * 2 % n;
            reach1 = (tmp * 2 + 1) % n;
            if (bitsnum[reach0] > bitsnum[tmp]){
                Q.push_front(reach0);
                bitsnum[reach0] = bitsnum[tmp];
            }
            if (bitsnum[reach1] > bitsnum[tmp] + 1){
                Q.push_back(reach1);
                bitsnum[reach1] = bitsnum[tmp] + 1;
            }
            
        }
        cout << bitsnum[0] << endl;
    }
}