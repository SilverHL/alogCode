#include <bits/stdc++.h>

using namespace std;

int n, m;

int sum(int s) 
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s;
        s = (s + 1) >> 2;
    }

    return sum;

}

int fun()
{
    if (n == 1) return m;
    int low = 1;
    int high = m;   //第一天的巧克力一定是大于等于１　小于等于m的
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (sum(mid) == m) return mid;  //第一天吃mid个巧克力 刚好吃完
        else if (sum(mid) < m) 
            low = mid - 1;
        else 
            high = mid + 1;
    }
    return high;
}

int main()
{
    cin >> n >> m;
    int res = fun();
    cout << res << endl;
}
