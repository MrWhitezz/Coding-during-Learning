#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<vector<int>>> Edge; // e, id, w
set<int> Left, Right;
vector<int> Del;
int main(){
    cin >> N >> M;
    Edge.resize(N + 5);
    for (int i = 1; i <= M; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        Edge[x].push_back({i, y, w});
        Edge[y].push_back({i, x, w});
    }

    for (int i = 1; i <= N; ++i){
        int lcost = 0, rcost = 0;
        vector<int> ledge, redge;
        for (auto info : Edge[i]){
            int e = info[0], id = info[1], w = info[2];
            if (id < i){
                if (Left.find(id) != Left.end()){
                    // id is in Left
                    if (w > 0) { rcost += w;      redge.push_back(e); }
                    else {       lcost += abs(w); ledge.push_back(e); }    
                }
                else {
                    // id is in Right
                    assert(Right.find(id) != Right.end());
                    if (w > 0) { lcost += w;      ledge.push_back(e); }
                    else {       rcost += abs(w); redge.push_back(e); }
                }
            }
        }
        if (lcost < rcost){
            Left.insert(i);
            for (auto e : ledge) Del.push_back(e);
        }
        else {
            Right.insert(i);
            for (auto e : redge) Del.push_back(e);
        }
    }

    cout << Del.size() << endl;
    for (auto del : Del) cout << del << endl;

}