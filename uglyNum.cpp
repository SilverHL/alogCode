#include <bits/stdc++.h>

using namespace std;

int findMin(int i, int j, int k)
{
    int res = min(i, min(j, k));
    return (res == i ? 0 : 
            (res == j ? 1 : 2));
}

int GetUglyNumber_Solution(int index) 
{
    if (index <= 0)
        return 0;

    int *a = new int[index];
    a[0] = 1;
    int d[3] = {2, 3, 5};
    int ans[3] = {2, 3, 5};
    int pos[3] = {0, 0, 0};

    int cur = 1;
    while (cur != index)
    {
        int m = findMin(ans[0], ans[1], ans[2]);
        if (a[cur-1] < ans[m])
            a[cur++] = ans[m];
        pos[m]++;
        ans[m] = a[pos[m]] * d[m];
    }

    cout << a[index-1];
    return a[index-1];

}
