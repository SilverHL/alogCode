/***
 * 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？
 * */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while (cin >> n) 
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) 
            cin >> nums[i];

        int minNum = 0, maxNum = 0;

        sort(nums.begin(), nums.end());

        //最大
        int m1 = 0, m2 = n-1, a = 1, b = 1;
        while (nums[m1+1] == nums[m1]) 
        {
            a++;
            m1++;
        }

        while (nums[m2] == nums[m2-1]) 
        {
            b++;
            m2--;
        }

        maxNum = a * b;

        //最小
        int minTemp = nums[n-1];
        for (int i = 1; i < n; i++) 
            if (nums[i] - nums[i-1] < minTemp) 
                minTemp = nums[i] - nums[i-1];

        if (minTemp > 0) 
        {
            for (int i = 1; i < n; i++) 
                if (nums[i] - nums[i-1] == minTemp) 
                    minNum++;
        }
        else 
        {
            for (int i = 1; i < n; i++) 
            {
                int j = i-1;
                while (nums[j] == nums[i] && j >= 0) 
                {
                    minNum++;
                    j--;
                }
            }
        }
    }

}
