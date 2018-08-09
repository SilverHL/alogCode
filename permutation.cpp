#include <bits/stdc++.h>

using namespace std;

void helper(string str, int i, vector<string>& res)
{
    if (i == str.length()-1) {
        res.push_back(str);
    } else {
        for (int j = i; j < str.length()-1; j++) {
            if (j == i || str[j] != str[i]) {
                swap(str[i], str[j]);
                helper(str, i+1, res);
                swap(str[i], str[j]);
            }            
            
        }
    }
}
vector<string> Permutation(string str)
{
    vector<string> res;

    if (str.length() > 0) {
        helper(str, 0, res);
        sort(res.begin(), res.end());
    }

    return res;
}
