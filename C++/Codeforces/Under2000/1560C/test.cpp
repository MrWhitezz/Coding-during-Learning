#include<bits/stdc++.h>
using namespace std;
int main(){
    int T, query;
    cin >> T;
    while (T--){
        cin >> query;
        if (query == 1){
            cout << "1 1" << endl;
            continue;
        }
        int circle = max(1, (int)sqrt(query) - 1);
        if ((circle + 1) * (circle + 1) < query) ++circle;
        int rest = query - circle * circle;
        if (rest <= circle + 1)
            cout << rest << " " << circle + 1 << endl;
        else
            cout << circle + 1 << " " << (2 * circle + 2 - rest) << endl;

        
    }
}