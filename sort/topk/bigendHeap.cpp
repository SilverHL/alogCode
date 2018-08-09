#include <iostream>

using namespace std;

void heap_insert()
{

}

void head_adjust(int arr[], int s, int len)
{
    int temp = arr[s];
    for (int i = 2 * s; i < len; i *= 2) 
    {
        if (i < len - 1 && arr[i] < arr[i+1]) 
            i++;
        if (arr[i] <= temp) 
            break;
        arr[s] = arr[i];
        s = i;
    }

    arr[s] = temp;
}
