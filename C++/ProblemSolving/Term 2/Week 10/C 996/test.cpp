#include<bits/stdc++.h>
using namespace std;
int n, beg, end;
int main()
{
    cin >> n;
    vector<pair<int, int>> work(n);//<beg,end>
    for (int i = 0; i < n; ++i)
        cin >> work[i].first >> work[i].second;
    sort(work.begin(), work.end());
    priority_queue<int, vector<int>, greater<int>> man;
    man.push(work[0].second);
    for (int i = 1; i < n; ++i){
        if (man.top() > work[i].first) man.push(work[i].second);
        else{
            man.pop();
            man.push(work[i].second);
        }
    }
    cout << man.size();
    return 0;
}