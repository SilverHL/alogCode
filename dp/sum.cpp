/***
 * 给定整数n，取若干个1到n的整数可求和等于整数m，编程求出所有组合的个数。
 * 比如当n=6，m=8时，有四种组合：[2,6], [3,5], [1,2,5], [1,3,4]。限定n和m小于120
 * **/

//dp[i][j]表示 从前i个数选出任意个数和为j的数量
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int dp[150][150];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;
    for (int i = 2; i <= m; i++)
        dp[1][i] = 0; 

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            if (j >= i)
                dp[i][j] = dp[i-1][j-i] + dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];

    cout << dp[n][m];
}


