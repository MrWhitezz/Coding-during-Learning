#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin >> n >> m;
    if (n > m) {long long temp = n; n = m; m = temp;}
    long long sqr = 0, rtg = 0;
    for (long long i = 1; i <= n; i++)
        sqr += (n - i + 1) * (m - i + 1);
    rtg = n * (n + 1) * m * (m + 1) / 4 - sqr;
    cout << sqr << " " << rtg;
    return 0;
}
