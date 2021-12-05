#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, tmp, depth = -1, sum = 0;
    cin >> n >> m;
    map<int,int> Gift;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        Gift.insert({tmp, i});
    }
    for (int i = 0; i < m; ++i){
        cin >> tmp;
        if (Gift[tmp] < depth) sum++;
        else{
            depth = Gift[tmp];
            sum += 2 * (depth - i) + 1;
        }
    }
    cout << sum;
    return 0;
}