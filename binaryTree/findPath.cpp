#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int> >res;
vector<int> curPath;

void dfs(TreeNode *root, int num, int sum)
{
    curPath.push_back(root->val);
    sum += root->val;

    if (sum == num && !root->left && !root->right) {
        res.push_back(curPath);
        return;
    }

    if (root->left) 
        dfs(root->left, num, sum);

    if (root->right)
        dfs(root->right, num, sum);

    curPath.pop_back();
}

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() > b.size();
}

vector<vector<int> >
FindPath(TreeNode* root,int expectNumber) 
{
    if (root == NULL)
        return res;

    dfs(root->left, expectNumber, 0);
    dfs(root->right, expectNumber, 0);

    return res;

}
