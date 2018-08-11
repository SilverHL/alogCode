/***
 * 希尔排序 时间复杂度在O(nlogn)到O(n*n)之间 
 * 其排序效率收到比较距离大小的影响 是不稳定排序
 * */

#include <bits/stdc++.h>

using namespace std;

void shell_sort(vector<int> &vec)
{
    int len = vec.size();
    int inc = len;
    do 
    {
        inc = inc / 3 + 1;
        for (int i = inc; i < len; i += inc)
        {
            if (vec[i] < vec[i - inc])
            {
                int tmp = vec[i];
                int j = i - inc;
                for ( ; j >= 0 && vec[j] > tmp; j -= inc )
                    vec[j+inc] = vec[j];
                vec[j+inc] = tmp;
            }
        }
    } while (inc > 1);
}
