#include<bits/stdc++.h>
using namespace std;
unordered_map<string, vector<double>> paper;
vector<pair<double, string>> score;
string name;
double i = 0;
const int N = 20;
void judge(ifstream &in);
int main()
{
    ifstream ifs;
    ofstream ofs;
    for (int j = 1; j <= N; ++j){
        ifs.open(to_string(j) + ".txt" , ios:: in);
        if (!ifs.is_open()) cout << "Fail to open\n";
        else judge(ifs);
        ifs.close();
    }
    for (auto it = paper.cbegin(); it != paper.cend(); ++it)
        score.push_back({accumulate(it->second.begin(), it->second.end(), 0.0) / it->second.size(), it->first});
    sort(score.begin(), score.end());
    ofs.open("rank.txt");
    ofs << "name\trank\tscore_ave\t\tscore1\tscore2\tscore3\tscore4\tscore5\tscore6\n";
    i = 1;
    for (auto it = score.crbegin(); it != score.crend(); ++it){
        ofs << it->second << '\t' << i++ << '\t' << it->first << "\t\t";
        for (auto jt = paper[it->second].begin(); jt != paper[it->second].end(); ++jt)
            ofs << *jt << '\t';
        ofs << endl;
    }
}
void judge(ifstream &in){
    i = 10;
    while (in >> name)
        paper[name].push_back(i-- / 10);
}