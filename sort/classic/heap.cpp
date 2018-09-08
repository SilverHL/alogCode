/***
 * 堆排 
 * 时间最好以及最坏复杂度都为O(nlogn) 空间复杂度 O(1) 
 * 不稳定 
 *
 * 如果角标从 0 开始 左子树 位置为 2n+1 右子树为2n+2;
 * 如果角标从 1 开始 左子树 位置为 2n   右子树为2n+1
 * */
#include <bits/stdc++.h>

using namespace std;

//大根堆
void heap_adjust(vector<int>& vec, int low, int high)
{
    int tmp = vec[low];
    int cur = low;
    int left = cur * 2 + 1;

    for ( ; cur <= high; cur = left, left = 2 * left + 1)
    {
        if (vec[left+1] > vec[left])
            left++;
        if (vec[cur] > vec[left])
            break;
        else 
        {
            vec[cur] = vec[left];
            vec[left] = tmp;
        }
    }

}

void heap_sort(vector<int>& vec)
{
    int len = vec.size();

    for (int i = len/2-1; i >= 0; --i)
        heap_adjust(vec, i, len-1);

    for (int i = len-1; i > 0; --i)
    {
        swap(vec[i], vec[0]);
        heap_adjust(vec, 0, i-1);
    }
}

int main()
{
    
}
