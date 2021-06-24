//This idea is like Huffman codes
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
ll appear, sum, cost;
int main()
{
    cin >> n >> k;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> nodes; // <sum of leaves, cost>
    for (int i = 0; i < n; ++i){
        cin >> appear;
        nodes.push({appear, 0});
    }
    int rest = n % (k - 1);
    if (rest != 1 && k > 2){
        if (!rest) rest += k - 1;
        sum = cost = 0;
        while (rest--){
            sum += nodes.top().first;
            cost += nodes.top().first + nodes.top().second;
            nodes.pop();
        }
        nodes.push({sum, cost});
    }
    while (nodes.size() >= k){
        sum = cost = 0;
        for (int i = 0; i < k; ++i){
            sum += nodes.top().first;
            cost += nodes.top().first + nodes.top().second;
            nodes.pop();            
        }
        nodes.push({sum, cost});
    }
    cout << nodes.top().second;
    return 0;
}
