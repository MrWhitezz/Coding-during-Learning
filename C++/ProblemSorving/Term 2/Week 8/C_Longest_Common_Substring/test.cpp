#include<bits/stdc++.h>
using namespace std;
string A, B, n, m;
int main()
{
    cin >> B >> A;
    int n = A.size();
    int m = B.size();
    static vector<int> pre(n + 1), cur(n + 1);
    for (int j = 1; j <= m; ++j){//in j iteration, cur[i] means i of A, j of B
        for (int i = 1; i <= n; ++i)
            if (A[i - 1] == B[j - 1]) cur[i] = pre[i - 1] + 1;
            else cur[i] = max(pre[i], cur[i - 1]);
        pre.swap(cur);
    }
    cout << pre[n];

    return 0;
}