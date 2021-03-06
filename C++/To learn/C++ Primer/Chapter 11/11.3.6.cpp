#include<bits/stdc++.h>
using namespace std;
const string &
transform(const string & s, const map<string, string> &m){
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}
map<string, string> buildMap(ifstream &map_file){
    map<string, string> trans_map;
    string key;
    string val;
    while (map_file >> key && getline(map_file, val)){
        if (val.size() > 1)
            trans_map[key] = val.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}
void word_transform(ifstream &map_file, ifstream &input){
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)){
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word){
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}
int main()
{
    ifstream in1, in2;
    in1.open("rule.txt");
    in2.open("source.txt");
    word_transform(in1, in2);
    in1.close();
    in2.close();
    return 0;
}