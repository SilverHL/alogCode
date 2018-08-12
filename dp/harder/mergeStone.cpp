/***
 * 区间动规 
 * 合并石子
 * */
#include <bits/stdc++.h>

using namespace std;

//dp[i][j] 用来表示从i 合并到j的最小代价
int main()
{
    int n, x;
    int sum[200];
    int dp[200][200];
    int tmp;

    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        sum[i] = sum[i-1] + tmp;
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= n; i++)
        {
            int j = i + len-1;
            if (j > n)
                continue;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j] + sum[j] - sum[i-1]);
        }

}

int main1()
{
    int n, x;
    int sum[200];
    int dp[200][200];
    int tmp;
    int s[200][200];

    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        sum[i] = sum[i-1] + tmp;
        dp[i][i] = 0;
        s[i][i] = i; 
    }

    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= n; i++)
        {   
            int j = i + len -1;
            if (j > n) 
                continue;
            for (int k = s[i][j-1]; k <= s[i+1][j]; k++)
            {
                if (dp[i][k] + dp[k+1][i] + sum[j] - sum[i-1] > dp[i][j])
                {
                    dp[i][j] = dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1];
                    s[i][j] = k;
                }
            }
        }

}
