#include<bits/stdc++.h>
using namespace std;
int N, K, begx = 1, endx = 1e9, x;
bool check(const vector<int> &arr, int x);
int main()
{
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    while (begx != endx){
        x = (begx + endx) / 2; // x < endx
        if (check(arr, x)) endx = x; // ensure endx is ok
        else begx = x + 1;
    }
    cout << begx;
    return 0;
}
bool check(const vector<int> &arr, int x){
    int k = K;
    for (int i = 0; i < N - 1; ++i)
        k -= (arr[i + 1] - arr[i] - 1) / x;
    return k >= 0;
}