/**
 * 世界上有10种人，一种懂二进制，一种不懂。那么你知道两个int32整数m和n的二进制表达，
 * 有多少个位(bit)不同么？
 * **/

#include <bits/stdc++.h>

using namespace std;

int countBitDiff(int m, int n)
{
    int tmp = m ^ n;
    int count = 0;
    while (tmp)
    {
        tmp = tmp & (tmp-1);
        count++;
    }

    return count;
}

int main()
{
    cout << countBitDiff(1999, 2299);
}

