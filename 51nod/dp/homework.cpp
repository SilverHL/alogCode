/***
一个学年由n天组成。A学校有m门课程，每天学生必须学习一门课，一门课程必须在一天内学习完。
在学习完第i门课程后，学生们会收到 xi 个家庭作业，其中 xi是区间[ai,bi]里的一个整数 。每门课还有一个属性
，就是复杂度 ci 。A学校现在要制他们的课程表，具体要求如下：
·在课程表中，随着天数的增加，课程的复杂度是严格递增的。
·除了第1天，每天的作业量必须是前一天的k倍，或者比前一天多k个作业。
（假设第i天的作业量为 xi ，则对于i(1＜i≤n)到满足 xi ＝ k+xi−1 或 xi ＝ k⋅xi−1 ）；
现在，给定天数n，系数k，和m门课程的ai，bi，ci（1≤i≤m）。要求计算一个学年可以
安排最大的总作业量( 总作业量的表达式是∑ni=1xi )是多少。

**/
//思路 : 动态规划 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 105;
const int maxm = 55;

struct Node 
{
    ll l, r, lim;
}node[maxn];

bool cmp2(Node a, Node b)
{
    return a.lim < b.lim;
};

int m, n;
ll k;
ll dp[maxm][maxn][maxn]; //作业量

int main()
{
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++)
        cin >> node[i].l >> node[i].r >> node[i].lim ;

    memset(dp, -1, sizeof(dp));
    sort(node, node+m, cmp2);
    for (int i = 0; i < m; i++)
        for (ll j = node[i].l; j <= node[i].r; ++j)
            dp[1][i][j-node[i].l] = 1ll * j;

    for (int i = 1; i <= n; i++)
        for (int j = i-1; j < m; j++)
            for (ll x = node[j].l; x <= node[j].r; x++)
            {
                if (dp[i][j][x-node[j].l] == -1)
                    continue;
                for (int jj = j+1; jj < m; jj++)
                {
                    if (node[jj].lim <= node[j].lim)
                        continue;

                    if (x*k >= node[jj].l && x*k <= node[jj].r)
                        if (dp[i][j][x-node[i].l] + x*k > dp[i+1][jj][x*k-node[jj].l])
                            dp[i+1][jj][x*k-node[jj].l] = 
                                dp[i][j][x-node[j].l] + x*k;

                    if ((x+k)*1ll >= node[jj].l && (x+k)*1ll <= node[jj].r)
                        if (dp[i+1][jj][1ll*(x+k)-node[jj].l] < dp[i][j][x-node[j].l]+1ll*(x+k))
                            dp[i+1][jj][1ll*(x+k)-node[jj].l] = 
                                dp[i][j][x-node[j].l]+1ll*(x+k);
                }
            }

    long long ans = -1;
    for (int i = 0; i < m; i++)
        for (ll j = node[i].l; j <= node[i].r; j++)
            if (dp[n][i][j-node[i].l] > ans)
                ans = dp[n][i][j-node[i].l];

    if (ans != -1) 
    {
        cout << "YES" << endl;
        cout << ans << endl;;

    }
    else 
        cout << "NO" << endl;
}

