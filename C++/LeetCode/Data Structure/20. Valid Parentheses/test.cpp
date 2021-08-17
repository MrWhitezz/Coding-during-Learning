// The Stack is just great!
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<int> left;
        for (auto ch : s){
            if (ch == '[' || ch == '{' || ch == '(')
                left.push(ch);
            else if (!left.empty() && 
            ((ch == ']' && left.top() == '[') || 
            (ch == '}' && left.top() == '{') || 
            (ch == ')' && left.top() == '(')))
                left.pop();
            else return false;
        }
        return left.empty();
    }
};