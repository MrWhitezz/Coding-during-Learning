#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
typedef struct line_segment {
    ll x1, y1, x2, y2;
} line_segment;
#define maxn 1005
line_segment line[maxn];
bool is_up[maxn];
ll s1, t1, s2, t2;
bool lie_2_side(line_segment A, line_segment B);
bool cross(line_segment A, line_segment B);
int f(ll a, ll b, ll c, ll x, ll y) {
    ll res = a * x + b * y + c;
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}
int ans = 0;
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> s1 >> t1 >> s2 >> t2;
        line[i].x1 = s1;
        line[i].y1 = t1;
        line[i].x2 = s2;
        line[i].y2 = t2;
    }
    for (int i = 0; i < n; ++i){
        is_up[i] = true;
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (is_up[j] && cross(line[i], line[j])){
                is_up[j] = false;
            }
        }
    }
    for (int i = 0; i < n; ++i){
        if (is_up[i]){
            ans++;
        }
    }
    cout << ans << endl;

}

bool lie_2_side(line_segment A, line_segment B){
    ll a = A.y2 - A.y1;
    ll b = A.x1 - A.x2;
    ll c = A.x2 * A.y1 - A.x1 * A.y2;
    return f(a, b, c, B.x1, B.y1) * f(a, b, c, B.x2, B.y2) <= 0;
}

bool cross(line_segment A, line_segment B){
    return lie_2_side(A, B) && lie_2_side(B, A);
}