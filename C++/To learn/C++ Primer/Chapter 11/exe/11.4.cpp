#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include <cctype>
using namespace std;
bool isPunct(char c){
    return ispunct(c);
}
void word_count_pro(map<string, int>& m){
    string word;
    while (cin >> word){
        for (auto& i : word){
            i = tolower(i);
        }
        //auto f = [](string:: iterator it){return ispunct(*it);};
        word.erase(remove_if(word.begin(), word.end(), isPunct), word.end());//cannot understand why?
        ++m[word];
    }
    for (auto &i : m){
        cout << i.first << " occurs " << i.second << " times.\n";
    }
}
int main()
{
    map<string, int> m;
    word_count_pro(m);

    return 0;
}