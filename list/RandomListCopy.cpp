#include <bits/stdc++.h>

using namespace std;

struct RandomListNode
{
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;

    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* 
Clone(RandomListNode* pHead)
{
    if (pHead == NULL)
        return NULL;
    RandomListNode *index = pHead;

    while (index) {
        RandomListNode *cp = new RandomListNode(index->label);
        cp->next = index->next;
        index->next = cp;
        index = cp->next;
    }

    index = pHead;
    
    while (index != NULL) {
        RandomListNode *cur = index->next;
        if (index->random) 
            cur->random = index->random->next;
        index = cur->next;
    }

    RandomListNode *nHead = pHead->next;
    RandomListNode *temp;
    index = pHead;
    while (index->next != NULL) {
        temp = index->next;
        index->next = temp->next;
        index = temp;
    }

    return nHead;
}
