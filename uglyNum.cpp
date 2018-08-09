#include <bits/stdc++.h>

using namespace std;

int findMin(int i, int j, int k)
{
    int res = min(i, min(j, k));
    return (res == i ? 0 : 
            (res == j ? 1 : 2));
}

int GetUglyNumber_Solution(int index) {
    if (index <= 0) 
        return -1;
    int *a = new int[index];
    a[0] = 1;

    int *pos = new int[3]{0, 0, 0};
    int *num = new int[3]{2, 3, 5};
    int *d = new int[3]{2, 3, 5};

    int cur = 1;
    while (cur != index) {
        int m = findMin(num[0], num[1], num[2]);
        if (a[cur-1] < num[m]) 
            a[cur++] = num[m];
        pos[m] += 1;
        num[m] = a[pos[m]] * d[m];

    }


    
}
