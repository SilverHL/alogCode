#include <bits/stdc++.h>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x) {}
};

ListNode* Merge(ListNode* p1, ListNode* p2)
{
    if (p1 == NULL&& p2 == NULL)
        return NULL;
    if (p1 == NULL)
        return p2;
    if (p2 == NULL)
        return p1;

    ListNode *head = NULL;
    ListNode *cur = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->val >= p2->val) {
            if (head == NULL) {
                head = cur = p1;
            } else {
                cur = cur->next;
                cur = p1;
            }
            p1 = p1->next;
        } else {
            if (head == NULL) {
                head = cur = p2;
            } else {
                cur = cur->next;
                cur = p2;
            }

            p2 = p2->next;
        }
    }

    if (p1 == NULL) {
        cur = p2;
    } 
    if (p2 == NULL) {
        cur = p1;
    }

    return head;
}

