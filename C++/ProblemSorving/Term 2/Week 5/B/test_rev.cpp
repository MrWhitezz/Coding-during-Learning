#include<bits/stdc++.h>
using namespace std;
int N, x, y;
int main()
{
    cin >> N;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    cin >> x;
    max_heap.push(x);
    cout << x << endl;
    for (int i = 0; i < (N - 1) / 2; ++i){
        cin >> x >> y;
        max_heap.push(x);
        max_heap.push(y);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if (max_heap.top() > min_heap.top()){
            x = min_heap.top();
            y = max_heap.top();
            min_heap.pop();
            max_heap.pop();
            min_heap.push(y);
            max_heap.push(x);
        }
        cout << max_heap.top() << endl;
    }
    return 0;
}