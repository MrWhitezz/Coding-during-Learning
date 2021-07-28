//I didnt't imagine it could be solved with 2 Pointers
//Here is a very ELEGANT algorithm
// try to remember and understand it
// https://en.wikipedia.org/wiki/Cycle_detection
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* fast = head, *slow = head;
        while(1){
            if (fast->next == NULL) return NULL;
            else fast = fast->next;
            if (fast->next == NULL) return NULL;
            else fast = fast->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        fast = head;
        while (fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};