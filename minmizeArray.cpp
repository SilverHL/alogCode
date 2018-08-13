/***
 * 有一个长度为N的序列。一开始，这个序列是1, 2, 3,... n - 1, n的一个排列。

对这个序列，可以进行如下的操作：

每次选择序列中k个连续的数字，然后用这k个数字中最小的数字替换这k个数字中的每个数字。

我们希望进行了若干次操作后，序列中的每个数字都相等。请你找出需要操作的最少次数。
***/
#include <iostream>

using namespace std;

int num[10050];

int main()
{
    int n, k;
    int pos;
    int res = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        if (num[i] == 1)
            pos = i;
    }

    int tmp = pos;
    while (tmp < n+1)
    {
        if (tmp == n)
            break;
        tmp += k-1;
        res++;
    }

    tmp = pos;
    while (tmp > 0)
    {
        if (tmp == 1)
            break;
        tmp -= (k-1);
        res++;
    }

    cout << res;

    
}

