#include<bits/stdc++.h>
using namespace std;
class Dist {
public:
    int val;
    int div = 1;
    bool operator<(const Dist &D1) const{
        return (val + div - 1) / div < (D1.val + D1.div - 1) / D1.div;
    }

    Dist(const int _val, const int _div): val(_val), div(_div){}
    Dist(): val(0), div(1){}
};

int main()
{
    Dist dist_max;
    priority_queue<Dist> Q;
    int N, K, Mi, Mi_;
    cin >> N >> K >> Mi_;
    for (int i = 1; i < N; ++i){
        Mi = Mi_;
        cin >> Mi_;
        Q.push(Dist (Mi_- Mi, 1));
    }
    for (int i = 0; i < K; ++i){
        dist_max = Q.top();
        if (((dist_max.val + dist_max.div - 1) / dist_max.div) == 1)
            {cout << 1; return 0;}
        dist_max.div++;
        Q.pop();
        Q.push(dist_max);
    }
    dist_max = Q.top();
    cout << (dist_max.val + dist_max.div - 1) / dist_max.div;
    return 0;
}