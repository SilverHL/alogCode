#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, a, b;
    int k;

    cin >> k;
    cin >> a >> x >> b >> y;

    long long int dp[201][1001];
    int p[201];

    for (int i = 0; i < 201; i++) 
        for (int j = 0; j < 1001; j++) 
            dp[i][j] = -1;
    
    dp[0][0] = 1;
    for (int i = 1; i <= x; i++) 
        p[i] = a;

    for (int i = x + 1; i <= x + y; i++)
        p[i] = b;


    for (int i = 0; i < x + y; i++) 
        for (int j = 0; j < k; j++) {
            if (j >= p[i]) 
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-p[i]]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    
    return dp[x+y][k];
}
