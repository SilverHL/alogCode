#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2)
{
    int len1 = 0, len2 = 0;

    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;

    while (p1 != NULL) {
        len1++;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        ++len2;
        p2 = p2->next;
    }

    if (len1 > len2) 
        swap(pHead1, pHead2);

    int res = (len1 > len2 ? len1 - len2 : len2 - len1);
    p1 = pHead1;
    p2 = pHead2;

    while (res--) 
        p2 = p2->next;

    while (p1 != NULL && p2 != NULL) {
        if (p1->val == p2->val) 
            break;
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}
