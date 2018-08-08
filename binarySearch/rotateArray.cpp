#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &ra, int low, int high)
{
    int min = INT_MAX;
    while (low != high) {
        if (min > ra[low])
            min = ra[low];
        low++;
    }    
    return min;
}
int minNumberInRotateArray(vector<int> rotateArray) 
{
    if (rotateArray.size() == 0) 
        return 0;

    int low = 0;
    int high = rotateArray.size();
    int mid;

    while (low <= high) {
        if (high - low == 1) {
            mid = high;
            break;
        }
        mid = (low + high) >> 1;

        if (rotateArray[low] == rotateArray[mid] && 
            rotateArray[mid] == rotateArray[high]) {
            return findMin(rotateArray, low, high);
        }

        if (rotateArray[mid] >= low) 
            low = mid;
        else 
            high = mid;
    }

}


