#include<bits/stdc++.h>
using namespace std;
bool Is_has_3(int x);
const int ArSize = 1005;
int main(){
    int likes[ArSize];
    int cur = 0, foo = 1, n, k;
    while (++cur && foo < ArSize){
        if (!Is_has_3(cur)) likes[foo++] = cur;
    }
    cin >> n;
    while (n--){
        cin >> k;
        cout << likes[k] << endl;
    }

    return 0;
    
}
bool Is_has_3(int x){
    if (!(x % 3) || x % 10 == 3) return true;
    else return false;
}