#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> S;
    int N, K, Mi, Mi_, dist;
    cin >> N >> K >> Mi_;
    for (int i = 1; i < N; ++i){
        Mi = Mi_;
        cin >> Mi_;
        S.insert(Mi_ - Mi);
    }
    for (int i = 0; i < K; ++i){
        dist = *S.rbegin();
        if (dist == 1) {cout << 1; return 0;}
        S.erase(--S.end());
        if (dist % 2) {S.insert(dist / 2); S.insert(dist / 2 + 1);}
        else {S.insert(dist / 2); S.insert(dist / 2);}
    }
    cout << *S.rbegin();
    return 0;
}