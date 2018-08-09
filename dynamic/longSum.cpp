#include <bits/stdc++.h>

using namespace std;

int 
FindGreatestSumOfSubArray(vector<int> array) 
{
    int sum = 0;
    int max = INT_MIN;
    for (int i = 0; i < array.size(); i++) {
        sum = sum < 0 ? array[i] : sum + array[i];
        max = max > sum ? max : sum;
    }

    return max;
}

int main()
{
    vector<int> vec = {1,-2,3,10,-4,7,2,-5};

    cout << FindGreatestSumOfSubArray(vec) << endl;
}
