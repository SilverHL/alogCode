#include <iostream>
#include <vector>

using namespace std;

int getPar(vector<int> &a, int low, int high)
{
    int key = a[low];

    while (low < high) 
    {
        while (low < high && a[high] >= key) 
            high--;
        a[low] = a[high];
        while (low < high && a[low] < key) 
            low++;
        a[high] = low;
    }

    return low;
}

int main()
{
    int tmp;
    int total = 0;
    vector<int> a;
    int k;
    while (cin >> tmp && tmp != '\n') 
        a.push_back(tmp);
    
    int low = 0;
    int high = a.size()-1;
    int index = getPar(a, low, high);
    
    while (index != k-1) 
    {
        if (index > k-1) 
        {
            high = index-1;
            index = getPar(a, low, high);
        } 
        if (index < k-1)
        {
            low = index+1;
            index = getPar(a, low, high);
        }
    }

    cout << index;

    
}
