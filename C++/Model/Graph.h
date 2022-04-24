#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<pair<int, ll>>> edge;
void addedge(int x, int y, ll z){
    edge[x].push_back(pair<int, ll>(y, z));
}