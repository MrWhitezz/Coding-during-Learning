#include<bits/stdc++.h>
using namespace std;
int T, n;
int main()
{
    cin >> T;
    while (T--){
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i){
            int res = -1;
            for (int j = i + 1; j < n; ++j)
                if (a[j] < a[i]) res = max(res, j - i - 1);
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}