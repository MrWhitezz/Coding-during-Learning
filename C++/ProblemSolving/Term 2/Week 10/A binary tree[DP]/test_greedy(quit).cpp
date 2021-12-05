// I have a greedy idea!
    // it is too annoying, I don't want to code
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll trial = 15, n, k, rest, tmp, sum;
int i = 0, j = 0;
int main()
{
    cin >> n >> k;
    rest = (1 << trial) - n;
    vector<ll> cost(20);
    for (int i = 0; i < 20; ++i)
        cost[i] = 1 << i; //cost when up from i to i + 1
    vector<pair<ll,ll>> leaves(n + 5); //<val, up>
    priority_queue<pair<double, int>> candidates;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        leaves[i] = pair<ll,ll>(tmp, 0);
        candidates.push({(double)tmp, i});
    }
    vector<pair<double, int>> PrimeCandidates(n + 5);
    while (rest && !candidates.empty()){
        PrimeCandidates.clear();
        i = j = 0;
        PrimeCandidates[0] = candidates.top();
        candidates.pop();
        while (candidates.top().first == PrimeCandidates[i].first) {PrimeCandidates[++i] = candidates.top(); candidates.pop();}
        sort(PrimeCandidates.begin(), PrimeCandidates.begin() + i + 1, 
            [leaves](const pair<double,int> x, const pair<double,int> y){return leaves[x.second].second > leaves[y.second].second;});
        while (j != i){
            if (cost[leaves[PrimeCandidates[j].second].second] <= rest){
                rest -= cost[leaves[PrimeCandidates[j].second].second++];
                if (leaves[PrimeCandidates[j].second].second < trial - 1) candidates.push({PrimeCandidates[i].first / 2, PrimeCandidates[j].second});
            }
            ++j;
        }
        while (j != i){
            if(cost[leaves[PrimeCandidates[j].second].second] <= rest) candidates.push(PrimeCandidates[j]);
            ++j;
        }
    }
    for (int i = 0; i < n; ++i)
        sum += leaves[i].first * ((ll)trial - leaves[i].second);
    cout << sum;

    return 0;
}