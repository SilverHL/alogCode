/****
 * 每个测试输入包含空格分割的n+1个整数，最后一个整数为k值,n
 * 不超过100。
 * ***/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getPartition(vector<int>& vec, int low, int high)
{
    int key = vec[low];

    while (low < high)
    {
        while (low < high && vec[high] >= key) 
            high--;
        vec[low] = vec[high];
        while (low < high && vec[low] < key)
            low++;
        vec[high] = vec[low];
    }
    vec[low] = key;
    return low;
  }

int main()
{
    vector<int> vec;
    int tmp;
    while (scanf("%d", &tmp))
    {    
        if (tmp == 0)
            break;
        vec.push_back(tmp);

    }
    int k = vec.back();
    vec.pop_back();

    int low = 0;
    int high = vec.size()-1;
    int index = getPartition(vec, 0, vec.size());

    while (index != k-1)
    {
        if (index < k-1)
        {
            low = index+1;
            index = getPartition(vec, low, high);
        } 
        else if (index > k-1)
        {
            high = index-1;
            index = getPartition(vec, low, high);
        }
    }

    sort(vec.begin(), vec.begin()+5);
    for (int i = 0; i <= index; i++)
        cout << vec[i] << " ";
}

