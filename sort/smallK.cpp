#include <bits/stdc++.h>

using namespace std;

int getPartition(int start, int end, vector<int>& num)
{
    int key = num[start];
    
    if (start >= end || num.empty()) 
        return -1;
    
    while (start < end) {
        while (start < end && num[end] > key) 
            end--;
        num[start] = num[end];

        while (start < end && num[start] <= key) 
            start++;
        num[end] = num[start];
    }

    num[end] = key;
    return end;

}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    int start = 0;
    int end = input.size()-1;
    int index = getPartition(start, end, input);

    while (index != (k-1)) {
        if (index > (k-1)) {
            end = index-1;
            index = getPartition(start, end, input);
        } else  {
            start = index+1;
            index = getPartition(start, end, input);
        }
    }

    vector<int> res;
    for (int i = 0; i < k; i++) 
        res.push_back(input[i]);

    return res;

}

int main()
{
    vector<int> input = {4,5,1,6,2,7,3,8};

    vector<int> res = GetLeastNumbers_Solution(input, 4);

    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << endl;
}
