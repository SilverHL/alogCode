#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isSubTree(TreeNode *p1, TreeNode *p2)
{
    if (p2 == NULL)
        return true;
    if (p1 == NULL)
        return false;

    if (p1->val == p2->val)
        return isSubTree(p1->left, p2->left) && 
                isSubTree(p1->right, p2->right); 
    else 
        return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (pRoot2 == NULL || pRoot1 == NULL)
        return false;

    return isSubTree(pRoot1, pRoot2) ||
            HasSubtree(pRoot1->left, pRoot2) || 
            HasSubtree(pRoot1->right, pRoot2) ;
}
