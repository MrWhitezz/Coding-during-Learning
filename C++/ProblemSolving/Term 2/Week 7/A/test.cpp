#include<bits/stdc++.h>
using namespace std;
int n, k;
// auto cmp1 = [](const int x, const int y){return x < y;};
// auto cmp2 = [](const int x, const int y){return x > y;};
bool cmp1 (const int x, const int y) {return x < y;}
bool cmp2 (const int x, const int y) {return x > y;}
void push_mono_que(deque<int> & q, int x, decltype(cmp1) cmp);
void print_slide (deque<int> &q, int a[], decltype(cmp1) cmp);
int main()
{
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    deque<int> mono_queue;
    print_slide(mono_queue, a, cmp2);
    print_slide(mono_queue, a, cmp1);

    return 0;
}
void print_slide (deque<int> &q, int a[], decltype(cmp1) cmp){
    for (int i = 0; i < k - 1; ++i)
        push_mono_que(q, a[i], cmp);
    for (int i = k - 1; i < n; ++i){
        push_mono_que(q, a[i], cmp);
        cout << q.front() << " ";
        if (a[i - k + 1] == q.front()) q.pop_front();
    }
    cout << endl;
    q.clear();
}
void push_mono_que(deque<int> & q, int x, decltype(cmp1) cmp){
    while (!q.empty() && cmp(q.back(), x))
        q.pop_back();
    q.push_back(x);
}