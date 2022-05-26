#include <bits/stdc++.h>
using namespace std;
#define N 105
int father[N];
int value[N];

void init(int n) {
  for (int i = 0; i <= n; i++) {
    father[i] = i;
    value[i] = 0;
  }
}

int Find (int x) {
    if (father[x] == x)
        return x;
 
    int temp = father[x];
    father[x] = Find(father[x]);
    value[x] += value[temp]; //结点x到根的距离
 
    return father[x];
}

int Union(int x, int y, int val) {
    int fx = Find(x);
    int fy = Find(y);
 
    if (fx == fy) //如果当前两点与之前距离有冲突
        if(value[y] != value[x] + val)
            return 1;
 
    father[fy] = fx; // fx as root
    value[fy] = value[x] - value[y] + val; //计算两点距离
    return 0;
}

int w, n, m;
int main() {
    cin >> w;
    while (w--) {
        cin >> n >> m;
        init(n);
        bool real = true;
        for (int i = 0; i < m; ++i) {
            int s, t, v;
            cin >> s >> t >> v;
            s--;
            if (Union(s, t, v))
                real = false;
        }
        if (real)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}