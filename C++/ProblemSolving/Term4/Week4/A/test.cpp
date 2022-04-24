#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
vector<int> x, y;
int n;
int main(){
    cin >> n;
    x.resize(n), y.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int id = n / 2;
    id = (n & 1) ? id : id - 1;
    printf("%d %d\n", x[id], y[id]);
}