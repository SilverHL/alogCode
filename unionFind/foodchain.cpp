/***
 * 有N只动物分别编号为1，2，……，N。所有动物都属于A，B，C中的一类。
 * 已知A能吃掉B，B能吃掉C，C能吃掉A。按顺序给出下面的两种信息共K条：
 * 第一种：x和y属于同一类；第二种：x吃y。然而这些信息可能会出错，
 * 有可能有的信息和之前给出的信息矛盾，也有的信息可能给出的x和y不在1到N的范围内。
 * 求在K条信息中有多少条是不正确的。计算过程中，我们将忽视诸如此类的错误信息。
 * **/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
    
const int maxn = 20000;
int n, k;
int x, y;
int f[3*maxn+1], size[3*maxn+1];
int t[3*maxn+1], a[3*maxn+10], b[3*maxn+10];

int getf(int x) 
{
    return x == f[x] ? x : f[x] = getf(f[x]);
}

void unite(int x, int y)
{
    int a = getf(x);
    int b = getf(y);
    if (a != b)
        f[b] = a;
    return ;
}

int main()
{
    int ans = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> t[i] >> a[i] >> b[i];

    for (int i = 0; i < 3*n; i++)
        f[i] = i;

    for (int i = 0; i < k; i++)
    {
        int tp = t[i];
        int x = a[i]-1, y = b[i] - 1;
        if (x < 0 || x >= n || y < 0 || y >= n)
        {
            ans++;
            continue;
        }

        if (tp == 0)
        {
            if (getf(x) == getf(y+n) || 
                getf(x) == getf(y+2*n))
                ans++;
            else
            {
                unite(x, y);
                unite(x+n, y+n);
                unite(x+n*2, y+n*2);
            }
        }
    }
}

