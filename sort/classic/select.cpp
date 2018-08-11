/***
 * 选择排序　时间复杂度N^2　空间复杂度O1 是稳定排序 
 * ***/

#include <bits/stdc++.h>

using namespace std;

int select_sort(vector<int>& vec)
{
    int len = vec.size();
    for (int i = 0; i < len-1; i++)
    {
        int min = i;
        for (int j = i+1; j < len; j++)
            if (vec[min] > vec[j])
                min = j;
        if (min != i)
        {
            int tmp = vec[i];
            vec[i] = vec[min];
            vec[min] = tmp;
        }
    }

}
