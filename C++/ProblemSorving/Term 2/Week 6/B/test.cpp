#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> Q;
    int n;
    string s;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i){
        getline(cin, s);
        if (s[0] == '+') Q.insert(stoi(s));
        else if (s[0] == '-'){
            if (!Q.empty()) Q.erase(Q.begin());
        }
        else if (Q.empty()) cout << "Error." << endl;
        else cout << *Q.begin() << endl;
    }
    return 0;
}
