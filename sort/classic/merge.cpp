/***
 * 归并排序 
 * 高级排序中唯一一个稳定排序
 * 时间复杂度 O(nlogn) 空间复杂度 O(n)
 * 数据量大时 注意空间开销
 * */

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> vec, int start, int mid, int end)
{
    vector<int> res(end);
    int i = start;
    int j = mid+1;
    int index = start;
    while (i != mid && j != end)
    {
        if (vec[i] < vec[j])
            res[index++] = vec[i++];
        else
            res[index++] = vec[j++];
    }

    if (i != mid)
        while (i != mid)
            res[index++] = vec[i++];

    if (j != end)
        while (j != end)
            res[index++] = vec[j++];
    
    for (int i = start; i != end; i++)
        vec[i] = res[i];
}

void merge_sort(vector<int> vec, int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    merge_sort(vec, start, mid);
    merge_sort(vec, mid+1, end);
    merge(vec, start, mid, end);
}
