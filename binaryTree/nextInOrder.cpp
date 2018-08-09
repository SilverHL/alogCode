#include <bits/stdc++.h>

using namespace std;

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode (int x) :
        val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode *GetNext(TreeLinkNode *pNode)
{
    if (pNode == NULL)
        return NULL;
    if (pNode->right != NULL) {
        TreeLinkNode *p = pNode->right;
        while (p->left) 
            p = p->left;
        return p;
    } else {
        TreeLinkNode *parent = pNode->next;
        if (pNode == parent->left)
            return parent;
        else {
            TreeLinkNode *g = parent->next;
            while (g != NULL && g->left != parent) {
                parent = g;
                g = g->next;
            }
            return g;
        }
    }
}
