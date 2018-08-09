#include <bits/stdc++.h>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size) 
{
    deque<int> deq;
    vector<int> res;

    if (num.size() == 0) 
        return res;

    for (int i = 0; i < num.size(); i++) {
        if (deq.size() == 0 || num[deq.back()] > num[i]) {
            deq.push_back(i);
        } else {
            while (deq.size() != 0 && num[deq.back()] < num[i]) 
                deq.pop_back();
            deq.push_back(i);
        }

        if (i - size == deq.front()) 
            deq.pop_front();
        if (i >= size-1)
            res.push_back(num[deq.front()]);
    }

    return res;
}


int main()
{
    vector<int> vec = {4, 3, 5, 4, 3, 3, 6, 7};
    vector<int> res = maxInWindows(vec, 3);

    for (int i = 0; i < res.size(); i++ )
        cout << res[i] << endl;
}
