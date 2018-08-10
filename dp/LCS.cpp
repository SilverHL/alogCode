#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;
    string str2;

    cin >> str1 >> str2;

    int dp[100][100];

    for (int i = 0; i < str1.length(); i++) 
        if (str1[i] == str2[0])
            dp[i][0] = 1;
        else 
            dp[i][0] = 0;

    for (int i = 0; i < str2.length(); i++) 
        if (str2[i] == str1[0]) 
            dp[0][i] = 1;
        else 
            dp[0][i] = 0;
    
    int max = 0;
    int row = 0;
    int line = 0;
    for (int i = 1; i < str1.length(); i++)
        for (int j = 1; j < str2.length(); j++) 
        {
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (max < dp[i][j]) 
                    max = dp[i][j];
                    row = i;
                    line = j;
            } 

        }

    string res = "";
    while (max--) 
    {
        res = str1[row--] + res;
        
    }

    cout << res;
}
