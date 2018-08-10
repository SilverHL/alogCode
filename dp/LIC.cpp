#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    int arr[100];
    int dp[100];

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    dp[0] = 1;

    for (int i = 1; i < n; i++) 
    {
        int j = 0, max = 0;
        
        while (i > j)
            if (dp[j] < dp[i] && dp[j] < max) 
                max = dp[j];
        dp[i] = max + 1;
    }



}
