#include <bits/stdc++.h>

using namespace std;

int LastRemaining_Solution(unsigned int n, unsigned int m)
{
    if (n == 0) 
        return -1;
    if (n == 1)
        return 0;

    return (LastRemaining_Solution(n-1, m) + m )% n;
}
