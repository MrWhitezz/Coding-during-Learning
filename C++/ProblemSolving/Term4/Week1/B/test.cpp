#include<bits/stdc++.h>
using namespace std;
string s0;
string vo = "aeiouAEIOU";
bool is_vowel(char ch){
    for (auto v : vo){
        if (v == ch)
            return true;
    }
    return false;
}

int num_letter(string t){
    int res = 0;
    for (auto ch : t){
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            res++;
    }
    return res;
}

string show_letter(string hint, int n){
    assert(hint.size() == s0.size());
    assert(n <= num_letter(s0));
    string ans = hint;
    int cnt = 0;
    for (int i = 0; i < s0.size(); ++i){
        if (cnt == n) break;
        char ch = s0[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            assert(ans[i] == '.');
            ans[i] = ch;
            ++cnt;
        }
    }
    return ans;
}

void test(){
    cout << is_vowel('c') << endl;
    cout << is_vowel('i') << endl;
    cout << is_vowel('A') << endl;
    cout << is_vowel('D') << endl;
}
int main(){
    getline(cin, s0);
    string h1 = s0;
    int len = num_letter(s0);
    for (auto &ch : h1){
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            ch = '.';
        }
    }
    int len2 = round(len / 3.0);
    string h2 = show_letter(h1, len2); 

    bool has_vo = false;
    string h3 = h2;
    for (int i = 0; i < s0.size(); i++){
        if (is_vowel(s0[i]) && h2[i] == '.'){
            has_vo = true;
            h3[i] = s0[i];
        }
    }

    if (has_vo == false){
        int len3 = round(len * 2.0 / 3.0);
        h3 = show_letter(h1, len3);
    }

    cout << h1 << endl;
    cout << h2 << endl;
    cout << h3 << endl;

}