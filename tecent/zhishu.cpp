/***
 * 给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
 * 如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
 * **/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> vec(1000, 1);
    cin >> n;
    for (int i = 2; i < 1000; i++) 
        for (int j = 2; i * j < 1000; j++) 
            if (vec[i]) 
                vec[i*j] = 0;

    int cnt = 0;
    for (int i = 2; i < n; i++ ) 
        if (vec[i] && vec[n-i])
            cnt++;

    cout << cnt;
    return 0;


}

