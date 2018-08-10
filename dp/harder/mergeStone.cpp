#include <bits/stdc++.h>

using namespace std;

int n;
int f[1000][1000] = {};
int sum[1000] = {};
int a[1000] = {};
int cost[1000][1000] = {};

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    for (int i = 1; i <= n; i++) 
        for (int j = i; j <= n; j++) 
            cost[i][j] = sum[j] - sum[i-1];

    for (int len = 2; len <= n; len++) 
        for (int i = 1; i <= n; i++) 
        {
            int j = i + len - 1;
            if (j > n) 
                continue;
            for (int k = i; k < j; k++) 
                if ((f[i][k] + f[k+1][j] + cost[i][j] < f[i][j]) || !f[i][j]) 
                    f[i][j] = f[i][k] + f[k+1][j] + cost[i][j];
        }

    cout << f[1][n];
    return 0;
}

