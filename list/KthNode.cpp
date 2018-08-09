#include <bits/stdc++.h>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
};


ListNode* 
FindKthToTail(ListNode* pListHead, unsigned int k) 
{
    ListNode *kth = pListHead;
    ListNode *first = pListHead;
    
    for (int i = 0; i < k; i++) {
        if (kth == NULL) 
            return NULL;
        kth = kth->next;
    }
    
    while (kth != NULL) {
        kth = kth->next;
        first = first->next;
    }

    return first;

}
