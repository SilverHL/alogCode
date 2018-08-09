#include <bits/stdc++.h>

using namespace std;
/*
int findFst(vector<int> data, int k, int beg, int end)
{
    if (beg == end)
        return 0;

    int mid = (end - beg) / 2 + beg;
    while (beg < end) {
        if (data[mid] < k) {
            beg = mid + 1;
        } else if (data[mid] > k){
            end = mid - 1;
        } else {
            if (data[mid-1] == k || beg == mid) 
                end = mid - 1;
            else 
                return mid;
        }
        mid = (end - beg) / 2 + beg;
    }

    return beg;
}

int findLst(vector<int> data, int k, int beg, int end)
{
    if (beg == end) 
        return 0;

    int mid = (end - beg) / 2 + beg;
    while (beg < end) {
        if (data[mid] > k) 
            end = mid;
        else if (data[mid] < k)
            beg = mid + 1;
        else {
            if (data[mid+1] == k || end == mid) 
                beg = mid + 1;
            else 
                return mid;
        }
        mid = (end - beg) / 2 + beg;
    }
    return beg;

}
int GetNumberOfK(vector<int> data ,int k) 
{
    if (data.size() <= 0) 
        return 0;

    int fst = findFst(data, k, 0, data.size()-1);
    int lst = findLst(data, k, 0, data.size()-1);

    return (fst - lst + 1);
}

int main()
{
    vector<int> vec = {1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8};

    cout << GetNumberOfK(vec, 3);
}
*/

int biSearch(vector<int> data, double k, int beg, int end)
{
    int mid = (beg - end) / 2 + beg;

    while (beg < end) {
        if (data[mid] < k) 
            beg = mid + 1;
        else 
            end = mid - 1;
    }

    return beg;
}

int GetNumberOfK(vector<int> data, int k)
{
    return biSearch(data, k+0.5, 0, data.size()-1)
            - biSearch(data, k-0.5, 0, data.size()-1);
}
