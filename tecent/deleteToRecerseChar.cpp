#include <bits/stdc++.h>

using namespace std;

#define UP 0
#define LEFT 1
#define LEFTUP 2

struct Node
{
    int val;
    int dir;
};

Node dp[100][100];
int max_ = 0;

void Max(int i, int j, string str1, string str2) 
{
    dp[i][j].val = dp[i-1][j].val;
    dp[i][j].dir = UP;

    if (dp[i][j-1].val > dp[i][j].val) 
    {
        dp[i][j].val = dp[i][j-1].val;
        dp[i][j].dir = LEFT;
    }

    int temp;
    if (str1[i] == str2[j]) 
        temp = dp[i-1][j-1].val + 1;
    else 
        temp = dp[i-1][j-1].val;

    if (temp > dp[i][j].val) 
    {
        dp[i][j].val = temp;
        dp[i][j].dir = LEFTUP;
    }

    if (dp[i][j].val > max_) 
        max_ = dp[i][j].val;
}

int find(string str1, string str2)
{   

    for (int i = 0; i <= str1.length(); i++) 
        for (int j = 0; j <= str2.length(); j++) 
        {
            dp[i][j].val = 0;
            dp[i][j].dir = UP;
        }

    for (int i = 1; i <= str1.length(); i++) 
        for (int j = 1; j <= str2.length(); j++) 
            Max(i, j, str1, str2);


}

int main()
{
    string str1, str2 = "";
    cin >> str1;

    for (int i = 0; i < str1.length(); i++) 
        str2 = str1[i] + str2;

    find(str1, str2);
    cout << str1.length() - max_;
}
