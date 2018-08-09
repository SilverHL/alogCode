#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
{
    if (pre.size() == 0) 
        return NULL;

    int size = pre.size();
    TreeNode *node = new TreeNode(pre[0]);

    vector<int> pre_left, pre_right, in_left, in_right;

    int mid;
    for (int i = 0; i < size; i++) 
        if (vin[i] == pre[0]) {
            mid = i;
            break;
        }

    for (int i = 0; i < mid; i++) {
        in_left.push_back(vin[i]);
        pre_left.push_back(pre[i+1]);
    }

    for (int i = mid+1; i < size; i++) {
        in_right.push_back(vin[i]);
        pre_right.push_back(pre[i]);
    }

    node->left = reConstructBinaryTree(pre_left, in_left);
    node->right = reConstructBinaryTree(pre_right, in_right);

}
