#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class cmp{
    bool operator() (ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for (auto list : lists){
            if (list) heap.push(list);
        }
        ListNode* head = new ListNode(), *cur = head;
        while(!heap.empty()){
            cur->next = heap.top();
            heap.pop();
            cur = cur->next;
            if (cur->next) heap.push(cur->next);
        }
        return head->next;
    }
};