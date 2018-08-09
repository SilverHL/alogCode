#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int aim, count;
    vector<int> v;
    int tmp;

    cin >> aim >> count;
    while (count--) {
        cin >> tmp;
        v.push_back(tmp);
    }

    int **dp = new int*[v.size()+1];
    for (int i = 0; i < v.size(); i++) 
        dp[i] = new int[aim+1];

    for (int i = 0; i < v.size(); i++) 
        for (int j = 0; j < aim+1; j++)
            dp[i][j] = -1;

    for (int i = 0; i < v.size(); i++)
        dp[i][0] = 1;

    for (int i = 0; i < v.size(); i++) {  
        if (i % v[i] == 0) 
            dp[0][i] = 1;
        else 
            dp[0][i] = 0;
    }

    for (int i = 0; i < v.size(); i++) 
        for (int j = 0; j < aim+1; j++) {
            if (j - v[i] >= 0) 
                //推出来的公式
                dp[i][j] = dp[i-1][j] + dp[i][j-v[i]];
            else 
                //如果当前值小于这个钱币的单张面额
                //就需要别的钱币　不用这一张
                dp[i][j] = dp[i-1][j];
        }

    return dp[v.size()-1][aim];
}
