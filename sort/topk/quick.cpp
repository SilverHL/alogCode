/***
 * 基于快排的topk 
 * */

#include <iostream>

using namespace std;

int getParition(int arr[], int low, int high)
{
    int key = arr[low];

    while (low < high) 
    {
        while (low < high && arr[high] >= key) 
            high--;
        arr[low] = arr[high];
        while (low < high && arr[low] < key) 
            low++;
        arr[high] = arr[low];
    }

    arr[low] = key;
    return low;
}

int top_k(int arr[], int k)
{
    if (arr == NULL || sizeof(arr) / sizeof(arr[0]) == 0) 
        return -1;
    int len = sizeof(arr) / sizeof(arr[0]);
    if (k < 0 || k > len)
        return -1;

    int low = 0, high = len-1;
    int index = getParition(arr, low, high);
    while (index != k) 
    {
        if (index > k) 
        {
            high = index - 1;
            index = getParition(arr, low, high);
        } else 
        {
            low = index + 1;
            index = getParition(arr, low, high);
        }
    }

    return arr[index];
}

int main()
{

}

