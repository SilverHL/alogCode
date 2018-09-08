/***
 * 东东从京京那里了解到有一个无限长的数字序列: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, ...(数字k在该序列中正好出现k次)。东东想知道这个数字序列的第n项是多少,你能帮帮他么
输入描述:
输入包括一个整数n(1 ≤ n ≤ 10^18)
**/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m = sqrt(2*n);
    if (m*(m+1) < 2*n) m++;
    cout << m;
}
