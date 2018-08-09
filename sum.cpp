#include <bits/stdc++.h>

using namespace std;

/***
int main()
{
    int n;
    int sum;
    int tmp;
    vector<int> v;
    int count = 0;
    cin >> n >> sum;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    auto beg = v.begin(), end = v.end()-1; 
    while (beg != end) {
        int tmp = *beg + *end;
        if (tmp == sum) {
            count++;
            if (*(beg+1) == *beg) 
                beg++;
            else if (*(end-1) == *end)
                end--;
            else 
                beg++;
        }
        else if (tmp > sum) 
            end--;
        else 
            beg++;
    }

    cout << count;

}

*************/

long long dp[1002][1002];

int main()
{
    int n, sum;
    cin >> n >> sum;
    int tmp;
    int v[1000];
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++) 
        dp[i][0] = 1;

    for (int i = 1; i < sum; i++) 
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++ )
        for (int j = 0; j <= sum; j++) 
            if (j >= v[i]) 
                dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i]];
            else 
                dp[i][j] = dp[i-1][j];

    cout << dp[n][sum];
}

