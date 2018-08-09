#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
/*
int TreeDepth(TreeNode* pRoot)
{
    if (pRoot == NULL) 
        return 0;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);

    return max(left, right) + 1;
}*/

int TreeDepth(TreeNode *pRoot)
{
    if (pRoot == NULL)
        return 0;

    deque<TreeNode *> deq;
    TreeNode *cur = NULL;
    TreeNode *nlast = pRoot;
    TreeNode *last = pRoot;
    int res = 1;

    while (!deq.empty()) {
        cur = deq.front();
        deq.pop_front();

        if (cur->left != NULL) {
            deq.push_back(cur->left);
            nlast = cur->left;
        }
        if (cur->right != NULL) { 
            deq.push_back(cur->right);
            nlast = cur->right;
        }
        if (cur == last) {
            ++res;
            last = nlast;
        }
    }

    return res;
}
