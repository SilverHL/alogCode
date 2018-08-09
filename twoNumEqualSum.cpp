#include <bits/stdc++.h>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum)
{
    vector<int> r;    
    if (array.size() == 0) 
        return r;
    int beg = 0;
    int end = array.size()-1;
    int res = INT_MAX;
    
    int tmp;

    while (beg <= end) {
        tmp = array[beg] + array[end];    
        if (tmp == sum) {
            r.push_back(array[beg]);
            r.push_back(array[end]);
            break;
        } else if (tmp > sum) {
            end--;
        } else if (tmp < sum) 
            beg++;
    }

    return r;
}
