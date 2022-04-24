#include<bits/stdc++.h>
using namespace std;
vector<string> sentence;
vector<int> punct;
queue<int> back_comma, front_comma;
enum{NONE, COMMA, STOP};
int num_words = 0;

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
                
        index++;
    }
    num_words = index;

    while (!back_comma.empty() || !front_comma.empty()){
        if (!back_comma.empty()){
            int id = back_comma.front();
            back_comma.pop();
            string s = sentence[id];
          
            for (int i = 0; i < sentence.size(); ++i){
                if (sentence[i] == s){
                    int ct_id = i;
                    if (punct[ct_id] == NONE){
                        punct[ct_id] = COMMA;
                        assert(ct_id < sentence.size() - 1);
                        front_comma.push(ct_id + 1);
                    }
                }
            }
            
        }

        if (!front_comma.empty()){
            int id = front_comma.front();
            front_comma.pop();
            string s = sentence[id];
    
            for (int i = 0; i < sentence.size(); ++i){
                if (sentence[i] == s){
                    int ct_id = i - 1;
                    assert(ct_id >= 0);
                    if (punct[ct_id] == NONE){
                        punct[ct_id] = COMMA;
                        back_comma.push(ct_id);
                    }
                }
            }
        }
        
        
    }

    print_sentence();    


}