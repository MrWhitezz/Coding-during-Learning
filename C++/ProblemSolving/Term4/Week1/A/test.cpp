#include<bits/stdc++.h>
using namespace std;
vector<string> sentence;
vector<int> punct;
queue<int> back_comma, front_comma;
unordered_map<string, vector<int>> same_word;
unordered_map<string, bool> has_back_searh, has_front_search;
enum{NONE, COMMA, STOP};

void print_sentence(){
    for (int i = 0; i < sentence.size() - 1; ++i){
        cout << sentence[i];
        switch (punct[i]){
            case NONE:  cout << " ";  break;
            case COMMA: cout << ", "; break;
            case STOP:  cout << ". "; break;
        }
    }
    cout << sentence.back() << ".\n";
}
int main(){
    string tmp;
    int index = 0;
    while(cin >> tmp){
        int PUNC = NONE;
        if (tmp.back() == '.') {PUNC = STOP;  tmp.pop_back();}
        if (tmp.back() == ',') {PUNC = COMMA; tmp.pop_back(); back_comma.push(index); front_comma.push(index + 1);}
        punct.push_back(PUNC);
        sentence.push_back(tmp);
                
        same_word[tmp].push_back(index);
        index++;
    }

    while (!back_comma.empty() || !front_comma.empty()){
        if (!back_comma.empty()){
            int id = back_comma.front();
            back_comma.pop();
            string s = sentence[id];
            if (has_back_searh[s] != true){
                has_back_searh[s] = true;
                for (auto ct_id : same_word[s]){
                    if (punct[ct_id] == NONE){
                        punct[ct_id] = COMMA;
                        if (ct_id >= sentence.size()) continue;
                        if (has_front_search[sentence[ct_id + 1]] == false)
                            front_comma.push(ct_id + 1);
                    }
                }
            }
        }

        if (!front_comma.empty()){
            int id = front_comma.front();
            front_comma.pop();
            string s = sentence[id];
            if (has_front_search[s] != true){
                has_front_search[s] = true;
                for (auto ct_id1 : same_word[s]){
                    int ct_id = ct_id1 - 1;
                    if (ct_id < 0) continue;
                    if (punct[ct_id] == NONE){
                        punct[ct_id] = COMMA;
                        if (has_back_searh[sentence[ct_id]] == false)
                            back_comma.push(ct_id);
                    }
                }
            }
        }
        
    }

    print_sentence();    

    
    

}