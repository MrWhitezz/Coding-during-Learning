#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int *a = new int(n + 5), *max = new int(n - k + 1 + 5), *min = new int (n - k + 1 + 5);
    priority_queue<int> max_heap, max_pop;
    priority_queue<int, vector<int>, greater<int>> min_heap, min_pop;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < k - 1; ++i){
        max_heap.push(a[i]);
        min_heap.push(a[i]);
    }
    for (int i = 0; i < n - k + 1; ++i){
        max_heap.push(a[k - 1 + i]);
        min_heap.push(a[k - 1 + i]);
        max[i] = max_heap.top();
        min[i] = min_heap.top();
        max_pop.push(a[i]);
        min_pop.push(a[i]);
        while (!max_pop.empty() && max_pop.top() == max_heap.top()){
            max_pop.pop();
            max_heap.pop();
        }
        while (!min_pop.empty() && min_pop.top() == min_heap.top()){
            min_pop.pop();
            min_heap.pop();
        }
    }

    for (int i = 0; i < n - k + 1; ++i)
        cout << min[i] << " ";
    cout << endl;
    for (int i = 0; i < n - k + 1; ++i)
        cout << max[i] << " ";
    return 0;
}
