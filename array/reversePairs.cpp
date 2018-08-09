#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

long long
finder(vector<int> &data, vector<int> &copy, int beg, int end)
{
    if (beg == end) {
        copy[beg] = data[beg];
        return 0;
    }

    int mid = (end - beg) / 2;
    
    long long left = finder(data, copy, beg, beg+mid);
    long long right =finder(data, copy, beg+mid+1,end);

    int i = beg+mid;
    int j = end;
    int ic = end;
    long long count = 0;

    while (i >= beg && j >= beg+mid+1) {
        if (data[i] > data[j]) {
            count = count + j - beg - mid;
            copy[ic--] = data[i--];
        } else {
            copy[ic--] = data[j--];
        }
    }

    for ( ; i >= beg; --i ) 
        copy[ic--] = data[i--];
    for ( ; j >= beg+mid+1; --j)
        copy[ic--] = data[j--];
    for (int i = 0; i < data.size(); i++) {
        data[i] = copy[i];
    }

    return left + right + count;
}

int InversePairs(vector<int> data) {
    if (data.size() == 0) 
        return 0;

    vector<int> copy(data);

    long long count = finder(data, copy, 0, data.size()-1);

    return count % mod;
}
