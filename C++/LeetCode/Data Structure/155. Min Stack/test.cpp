#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> data, mindata;
    /** initialize your data structure here. */
    MinStack() {
    
    }
    
    void push(int val) {
        data.push(val);
        if (mindata.empty() || val <= mindata.top()) mindata.push(val);
    }
    
    void pop() {
        if (data.top() == mindata.top()) mindata.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mindata.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */