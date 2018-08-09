#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* Convert(TreeNode* root)
{
    if (root == NULL) 
        return NULL;

    TreeNode *cur = NULL;
    stack<TreeNode *> sta;
    TreeNode *head = NULL;
    TreeNode *pre = NULL;
    bool fst = true;

    sta.push(root);
    while (!sta.empty() || cur != NULL) {
        while (cur != NULL) {
            sta.push(cur);
            cur = cur->left;
        }

        cur = sta.top();
        sta.pop();

        if (fst) {
            head = cur;
            cur->left = pre;
            pre = cur;
            fst = NULL;
        } else {
            cur->left = pre;
            pre->right = cur;
            pre = cur;
        }

        cur = cur->right;
    }

    return head;
}
