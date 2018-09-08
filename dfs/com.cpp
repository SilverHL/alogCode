/***
 * 小明拿到了一个数列a1 , a2 , ... an ，小明想知道存在多少个区间[l,r]同时满足下列两个条件：
1、r-l+1=k;
2、在a l , a l+1,...ar中，存在一个数至少出现了 t 次。
**/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumOfSection(vector<int> arr, int k ,int t)
    {
        int ret = 0;
        unordered_map<int, int> record;//val:frequency
        //滑动窗口为[i,j] j=k+i-1;
        for (int i = 0 ; (k+i-1) < arr.size(); i++) 
        {
            for (int j =i; j<= k+i-1; j++) 
            {
                record[arr[j]]++;
            }
            for (auto iter = record.begin(); iter != record.end(); iter++)
            {
                if (iter->second >= t)
                {
                    ret++;
                    break;
                }else
                    continue;
            }
            record.clear();
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    int n,k,t;
    if ( n<k || t<=0) 
    {
        return 0;
    }
    while (cin>>n>>k>>t) 
    {
        std::vector<int> vec;
        for (int i = 0; i < n; i++) 
        {
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }
        cout<<Solution().findNumOfSection(vec,k,t)<<endl;
    }
    return 0;
}
