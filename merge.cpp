/***
用x,y表示一个整数范围区间，现在输入一组这样的范围区间(用空格隔开)，
请输出这些区间的合并。
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, r;
    map<int, int> m;
    while (scanf("%d,%d", &l, &r) != EOF)
        m[l] = r;

    for (int i = 0; i < m.size(); i++)
    {
        auto tmp = lower_bound(m.begin(), m.end(), m[i]);
        if (tmp != m.end())
        {
            pair<int, int> it = *tmp;     
            m[i] = it.second; 
            m.erase(tmp);
        }
    }

    for (int i = 0; i < m.size(); i++)
    {
        
    }

}

