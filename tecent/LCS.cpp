#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int find(string str1, string str2)
{
    int dp[100][100];
    int max = 0;

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < str1.length(); i++) 
        if (str1[i] == str2[0]) 
            dp[i][0] = 1;
        else 
            dp[i][0] = 0;

    for (int i = 0; i < str1.length(); i++)
        if (str2[i] == str1[0]) 
            dp[0][i] = 1;
        else 
            dp[0][i] = 0;

    for (int i = 0; i < str1.length(); i++) 
        for (int j = 0; j < str2.length(); j++) 
            if (str1[i] == str2[j]) 
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max)
                    max = dp[i][j];
            } 

    return max;
}

int main()
{
    string str1;
    string str2;

    cin >> str1;
    for (int i = 0; i < str1.length(); i++) 
        str2 = str1[i] + str2;

    cout << str1.length() - find(str1, str2);
}
