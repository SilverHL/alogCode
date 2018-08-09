#include <bits/stdc++.h>

using namespace std;

vector<int> mutiply(const vector<int>& A)
{
    vector<int> res;

    if (A.size() == 0) 
        return res;

    int tmp = 1;
    int len = A.size();
    
    res.push_back(tmp);
    for (int i = 1; i < len; i++) 
        res.push_back(res.back()*A[i-1]);

    tmp = 1;
    for (int i = len-1; i >= 0; --i) {
        res[i] = res[i] * tmp;
        tmp *= A[i];
    }

    return res;
    
}
