#include<bits/stdc++.h>
using namespace std;
int T, n;
pair<int, int> tmp;
int main()
{
    cin >> T;
    deque<pair<int, int>> mono; // first pos, second val
    vector<pair<int, int>> choice;
    for (int i = 0; i < T; ++i){
        cin >> n;
        int a[n];
        mono.clear();
        choice.clear();
        for (int j = 0; j < n; ++j){
            cin >> a[j];
            while(!mono.empty() && mono.back().second >= a[j])
                mono.pop_back();
            mono.push_back({j, a[j]});
        }
        while (!mono.empty()){
            tmp = mono.front();
            choice.push_back(tmp);
            mono.pop_front();
        }

        for (int j = 0; j < n; ++j){
            int l = 0, r = choice.size() - 1;
            if (a[j] <= choice[0].second){
                cout << -1 << " ";
                continue;
            }
            while (r > l){
                int med = (l + r) / 2;
                if (choice[med].second >= a[j]){
                    r = med;
                }
                else l = med + 1;
            }
            if (a[j] > choice[choice.size() - 1].second){
                cout << choice[choice.size() - 1].first - j - 1 << " ";
                continue;
            }
            if (choice[r - 1].first - j - 1 >= 0)
                cout << choice[r - 1].first - j - 1 << " ";
            else
                cout << -1 << " ";
        }
        cout << endl;
    }
    return 0;
}