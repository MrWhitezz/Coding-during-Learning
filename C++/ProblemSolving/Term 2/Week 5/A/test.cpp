#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, b, index = 0, res = 0;
    cin >> n >> b;
    int a[n], cnt[n];
    for (int i = 0; i < n; ++i){
        cnt[i] = 0;
        cin >> a[i];
        index = a[i] == b ? i : index;
    }
    cnt[index] = 0;
    for (int j = index + 1; j < n; ++j)
        cnt[j] = cnt[j - 1] + (a[j] > b ? 1 : -1);
    for (int j = index - 1; j >= 0; --j)
        cnt[j] = cnt[j + 1] + (a[j] > b ? 1 : -1);
    multiset<int> M;
    for (int j = index + 1; j < n; ++j)
        M.insert(cnt[j]);
    for (int j = 0; j < index; ++j)
        res += M.count(-cnt[j]);
    for (int j = 0; j < n; ++j)
        if (!cnt[j]) res++;
    cout << res;
    return 0;
}