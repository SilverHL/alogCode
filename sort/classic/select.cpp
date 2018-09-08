/***
 * 选择排序　时间复杂度N^2　空间复杂度O1 是不稳定排序 
 * ***/

#include <bits/stdc++.h>

using namespace std;

void select_sort(vector<int>& vec)
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

int main()
{
    vector<int> ivec = {232, 3, 54, 32, 98, 91};
    select_sort(ivec);
    for_each(ivec.begin(), ivec.end(), [&](const int& x){ cout << x << " "; });
}
