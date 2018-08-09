#include <bits/stdc++.h>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
};

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
    if (pHead == NULL || pHead->next == NULL)
        return NULL;
    ListNode *slow = pHead;
    ListNode *fast = pHead;

    while (slow != fast) {
        
        if (slow->next != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        } else 
            return NULL;
    }

    fast = pHead;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;


    
}
