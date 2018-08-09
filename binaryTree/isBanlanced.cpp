#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int getDepth(TreeNode *root)
{
    if (root  == NULL) return 0;

    int left = getDepth(root->left);
    if (left == -1) return -1;

    int right = getDepth(root->right);
    if (right == -1) return -1;

    return abs(left - right) > 1 ? -1 : 1 + max(left, right);
}
