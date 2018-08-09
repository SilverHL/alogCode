#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 50;

int getHigest(int num)
{
    int res = 0;
    while (num)
    {
        num >>= 1;
        res++;
    }

    return res;
}

int main()
{
    int n;
    vector<int> paint(N, 0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> paint[i];
    
    sort(paint.begin(), paint.end());
    int big = n-1;
    int sml = big-1;
    int ans = 0;

    while (paint.size() > 2) 
    {
        if (getHigest(paint[big]) == getHigest(paint[sml])) 
        {
            int tmp = paint[big] ^ paint[sml];
            if (find(paint.begin(), paint.end(), tmp) == paint.end()) 
            {
                paint.push_back(tmp);
                sort(paint.begin(), paint.end());
                big++;
                sml++;
           }
        } else {
            ans++;
        }
        big--;
        sml--;
        paint.pop_back();

    }

    cout <<  ans+2;
    return 0;
}


