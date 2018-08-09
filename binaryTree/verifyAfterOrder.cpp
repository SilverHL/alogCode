#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isBST(int beg, int end, vector<int> seq)
{
    int flag = 1;
    int mid;
    if (beg >= end)
        return true;
    for (int i = beg; i < end; i++) {
        if (flag) {
            if (seq[i] > seq[end]) { 
                flag = 0;
                mid = 1;
            }
        } else {
            if (seq[i] < seq[end]) 
                return false;
        }
    }

    return isBST(beg, mid-1, seq) && 
            isBST(mid, end-1, seq);
}

bool VerifySquenceOfBST(vector<int> sequence) 
{
    if (sequence.size() == 0) 
        return false;
    return isBST(0, sequence.size()-1, sequence);
}
