#include <bits/stdc++.h>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
};

ListNode* ReverseList(ListNode* pHead) {
    ListNode *cur = pHead;
    ListNode *pre = NULL;
    ListNode *rhead = NULL;
    ListNode *tmp = NULL;

    while (cur != NULL) {
        tmp = cur->next;
        cur->next = pre;
        if (cur != NULL) 
            rhead = cur;
        pre = cur;
        cur = tmp;
    }

    return rhead;
    
}
