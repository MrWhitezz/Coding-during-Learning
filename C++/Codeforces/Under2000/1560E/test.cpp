#include<bits/stdc++.h>
using namespace std;
string generate(const string& s, const string& seq);
int main(){
    int T;
    string t, s, seq, my_t;
    bool divide_flag;
    unordered_map<char, int> hashmap;
    cin >> T;
    while (T--){
        cin >> t;
        divide_flag = true;
        hashmap.clear();
        seq.clear();
        for (auto it = t.rbegin(); it != t.rend(); ++it){
            if (!hashmap[*it]){
                seq.push_back(*it);
            }
            ++hashmap[*it];
        }
        reverse(seq.begin(), seq.end()); // remenber this syntax
        for (int i = 1; i <= seq.size(); ++i){
            if (hashmap[seq[i - 1]] % i != 0) divide_flag = false;
            hashmap[seq[i - 1]] /= i;
        }
        if (!divide_flag){
            cout << -1 << endl;
            continue;
        }
        int len = 0;
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it)
            len += it->second;
        s = string(t.begin(), t.begin() + len);
        my_t = generate(s, seq);
        if (t == my_t)
            cout << s << " " << seq << endl;
        else cout << -1 << endl;

    }
    return 0;
}
string generate(const string& s, const string& seq){
    string tt, ss = s;
    for (int i = 0; i < seq.size(); ++i){
        tt += ss;
        ss.erase(remove(ss.begin(), ss.end(), seq[i]), ss.end()); // remember this patterm: erase-remove
    }
    return tt;
}