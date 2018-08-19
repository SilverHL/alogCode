/**
 * 风口之下，猪都能飞。当今中国股市牛市，真可谓“错过等七年”。 给你一个回顾历史的机会，
 * 已知一支股票连续n天的价格走势，以长度为n的整数数组表示，数组中第i个元素（prices[i]）代表该股票第
 * i天的股价。 假设你一开始没有股票，但有至多两次买入1股而后卖出1股的机会，并且买入前一定要先保证手上没有股票。
 * 若两次交易机会都放弃，收益为0。 设计算法，计算你能获得的最大收益。 
 * 输入数值范围：2<=n<=100,0<=prices[i]<=100
 * */

/***
 * wocao这个解法太吓人了
 * **/

#include <bits/stdc++.h>

using namespace std;

int calculateMax(vector<int> prices) 
{
    int firstBuy = INT_MIN, firstSell = 0;
    int secondBuy = INT_MIN, secondSell = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        firstBuy = max(firstBuy, -prices[i]);
        firstSell = max(firstSell, firstBuy + prices[i]);
        secondBuy = max(secondBuy, firstSell - prices[i]);
        secondSell = max(secondSell, secondBuy + prices[i]);
    }

    return secondSell;
}

int main()
{
    vector<int> vec = {3,8,5,1,7,8};
    cout << calculateMax(vec);
}

