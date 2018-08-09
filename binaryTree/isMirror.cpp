#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool mir(TreeNode *left, TreeNode *right)
{
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;
    if (left->val != right->val)
        return false;

    return mir(left->left, right->right) &&
            mir(left->right, right->left);
}

bool isSymmetrical(TreeNode *pRoot)
{
    if (pRoot == NULL)
        return true;

    return mir(pRoot->left, pRoot->right);
}
