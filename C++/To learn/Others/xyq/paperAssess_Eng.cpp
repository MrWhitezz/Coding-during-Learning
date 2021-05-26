#include<bits/stdc++.h>
using namespace std;
unordered_map<string, vector<double>> paper;
vector<pair<double, string>> score;
string name;
double i = 0;
const int N = 3;
void judge(ifstream &in);
int main()
{
    ifstream ifs;
    for (int j = 1; j <= N; ++j){
        ifs.open(to_string(j) + ".txt" , ios:: in);
        if (!ifs.is_open()) cout << "Fail to open\n";
        else judge(ifs);
        ifs.close();
    }
    for (auto it = paper.cbegin(); it != paper.cend(); ++it)
        score.push_back({accumulate(it->second.begin(), it->second.end(), 0.0) / it->second.size(), it->first});
    sort(score.begin(), score.end());
    cout << "name\trank\tscore\n";
    i = 1;
    for (auto it = score.crbegin(); it != score.crend(); ++it){
        cout << it->second << '\t' << i++ << '\t' << it->first << endl;
    }
}
void judge(ifstream &in){
    i = 10;
    while (in >> name)
        paper[name].push_back(i-- / 10);
}