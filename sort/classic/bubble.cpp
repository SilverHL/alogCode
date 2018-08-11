/**
 * 冒泡排序　时间复杂度为n^2 空间复杂度为１
 * 是稳定排序　在数据有序时可以达到ON的复杂度　
 * 比较适用于　数据量不大　基本有序　
 * **/
#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int>& vec)
{
    int len = vec.size();
    for (int i = 0; i < vec.size()-1; i++)
        for (int j = i; j < vec.size(); j++)
            if (vec[i] > vec[j])
                swap(vec[i], vec[j]);
}
