/***
 * 插排
 * 
 * 时间复杂度最好 则为O(N) 
 * 最差O(N^2) 空间复杂度O(1) 
 * 平均时间复杂度为O(N^2)
 * 数据有序的情况下 可以达到O(N)的时间复杂度
 * **/

#include <bits/stdc++.h>

using namespace std;

void insert_sort(vector<int> &vec)
{
    int len = vec.size();

    for (int i = 1; i < len; i++) 
    {
        if (vec[i] < vec[i-1])
        {
            int tmp = vec[i];
            int j = i - 1;
            for ( ; j >= 0 && vec[j] > tmp; --j )
                vec[j+1] = vec[j];
            vec[j+1] = tmp;
        }
    }
}
