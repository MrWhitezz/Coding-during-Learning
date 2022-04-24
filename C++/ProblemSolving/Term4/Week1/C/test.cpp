#include<bits/stdc++.h>
using namespace std;
string S;

int brace_find(int fir);
void re_print(int st, int ed, int n);

int main(){
    cin >> S;
    re_print(0, S.size() - 1, 1);

}

int brace_find(int fir){
    assert(S[fir] == '{');
    int left_num = 1;
    int lst = fir;
    while (left_num > 0){
        ++lst;
        if (S[lst] == '{')
            left_num++;
        if (S[lst] == '}')
            left_num--;
    }
    return lst;
}
void re_print(int st, int ed, int n){
    // printf("1\n");
    if (n > 1){
        for (int i = 0; i < n; ++i){
            re_print(st, ed, 1);
        }
        return;
    }

    int pos = st;
    while (pos <= ed){
        if (S[pos] >= 'a' && S[pos] <= 'z'){
            cout << S[pos];
            pos++;
        }
        else if (S[pos] >= '0' && S[pos] <= '9'){
            int times = atoi((S.substr(pos)).c_str());
            while (S[pos] >= '0' && S[pos] <= '9') ++pos;
            assert(S[pos] == '{');
            int dpos = brace_find(pos);
            re_print(pos + 1, dpos - 1, times);
            re_print(dpos + 1, ed, 1);
            break;
        }
    }
}