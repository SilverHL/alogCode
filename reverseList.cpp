#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int x) : data(x){}
};

vector<int> 
printListFromTailToHead(ListNode* head) 
{
    ListNode *cur = head;
    ListNode *rhead = NULL;
    ListNode *tmp = NULL;
    ListNode *pre = NULL;

    while (cur != NULL) {
        ListNode *tmp = cur->next;
        cur->next = pre;
        if (tmp != NULL) 
            rhead = tmp;
        pre = cur;
        cur = tmp;
    }
    vector<int> res;
    while (rhead) {
        res.push_back(rhead->data);
        rhead = rhead->next;
    }

    return res;
}

int main()
{
    
}
