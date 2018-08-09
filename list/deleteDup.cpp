#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {}
};

ListNode *deleteDuplication(ListNode *pHead)
{
    ListNode *first = new ListNode(-1);
    first->next = pHead;

    ListNode *cur = pHead;
    ListNode *pre = first;
    ListNode *tmp;
    while (cur != NULL && cur->next != NULL) {
        if (cur->val == cur->next->val) {
            int val = cur->val;
            while (cur != NULL && cur->val == val) {
                tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            pre->next = cur;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }

    return first->next;
  }

