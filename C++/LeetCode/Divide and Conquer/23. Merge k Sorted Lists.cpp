#include <bits/stdc++.h>
using namespace std;
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
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
void insert(ListNode **l, int x) // left insert
{
   ListNode *tmp = *l;
   ListNode *l0 = new ListNode(x);
   *l = l0;
   l0->next = tmp;
}
ListNode *merge(ListNode *l1, ListNode *l2)
{
   if (l1 == nullptr) return l2;
   if (l2 == nullptr) return l1;
   ListNode **pos1 = &l1, **pos2 = &l2;
   while ((*pos2) != nullptr){
      if ((*pos2)->val < (*pos1)->val) {
         insert(pos1, (*pos2)->val);
         { pos2 = &(*pos2)->next; continue;}
      }
      else if ((*pos1)->next == nullptr) { (*pos1)->next = *pos2;  break;}
      else{ pos1 = &(*pos1)->next; continue;}
   }
   return l1;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        vector<ListNode *> list2;
        auto it = lists.begin();
        for (; it + 1 != lists.end() && it != lists.end(); it += 2)
           list2.push_back(merge(*it, *(it + 1)));
        if (it != lists.end()) list2.push_back(*it);
        return mergeKLists(list2);   
    }
};
int main()
{
   ListNode *l1 = getlist(), *l2 = getlist(), *l3 = merge(l1, l2);
   printlist(l3);
   return 0;
}