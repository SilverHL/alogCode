#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int counter = 0;

TreeNode *KthNode(TreeNode *pRoot, int k)
{
    while (pRoot != NULL) {
        TreeNode *node = KthNode(pRoot->left, k);
        if (node != NULL) 
            return node;
        counter++;
        if (counter == k)
            return node;
        node = KthNode(pRoot->right, k);
        if (node != NULL)
            return node;
    }

    return NULL;
}


