//understood the problem incorrectyly
//The substring should be consecutive
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A, B;
    cin >> A >> B;
    vector<int> pre(A.size() + 1), cur(A.size() + 1);

    for (int j = 1; j <= B.size(); ++j){//in j iteration, cur[i] means i of A, j of B
        for (int i = 1; i <= A.size(); ++i)
            if (A[i - 1] == B[j - 1]) cur[i] = pre[i - 1] + 1;
            else cur[i] = max(pre[i], cur[i - 1]);
        pre.swap(cur);
    }
    for (int i = 1; i <= A.size(); ++i)
        cout << pre[i] << " ";

    return 0;
}