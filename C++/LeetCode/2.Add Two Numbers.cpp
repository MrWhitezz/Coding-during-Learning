#include<bits/stdc++.h>
using namespace std;
//感觉这是一道链表入门级别的练习题，可以用来复习链表构造、访问的基本知识
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *res = new ListNode, **p = &res;
        int temp = 0;
        while(p1 != NULL || p2 != NULL)
        {
            temp = 0;
            temp += p1 == NULL ? 0 : p1->val;
            temp += p2 == NULL ? 0 : p2->val;
            if ((*p) == NULL)
                *p = new ListNode;
            (*p)->val = temp;
            p = &((*p)->next);
            if (p1 != NULL)
                p1 = p1->next;
            if (p2 != NULL)
                p2 = p2->next;
        }

        temp = 0;
        ListNode *p3 = res;
        while (p3 != NULL)
        {
            p3->val += temp;
            temp = p3->val / 10;
            p3->val %= 10;
            if (p3->next != NULL)
                p3 = p3->next;
            else
                break;
        }
        if (temp != 0)
        {
            p3->next = new ListNode(temp);
        }
        return res;
    }
};

ListNode *getlist()
{
    cout << "Enter the length of the list: ";
    int len;
    cin >> len;
    ListNode *res = new ListNode, **p = &res;
    for (int i = 0; i < len; i++)
    {
        cin >> (*p)->val;
        (*p)->next = new ListNode;
        p = &((*p)->next);
    }
    *p = NULL;
    return res;
}
void printlist(ListNode *l)
{
    while (l != NULL)
    {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}
int main()
{
    Solution s;
    ListNode *l1 = getlist(), *l2 = getlist(), *l = s.addTwoNumbers(l1, l2);
    printlist(l);
}