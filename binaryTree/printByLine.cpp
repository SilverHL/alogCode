#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> PrintFromTopToBottom(TreeNode* root) 
{
    vector<int> res;
    deque<TreeNode *> deq;
    TreeNode *last = root;
    TreeNode *nlast = root;
    TreeNode *cur = NULL;

    deq.push_back(root);

    while (!deq.empty()) {
        cur = deq.front();
        deq.pop_front();

        res.push_back(cur->val);
        if (cur->left) {
            deq.push_back(cur->left);
            nlast = cur->left;
        }

        if (cur->right) {
            deq.push_back(cur->right);
            nlast = cur->right;
        }

        if (cur == last) {
            last = nlast;
        }

    }


}
