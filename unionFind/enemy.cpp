/***
 * 俗话说得好，敌人的敌人就是朋友。
现在有n个人，编号1至n，初始互不相识。接下来有m个操作，操作分为两种：

（1）检查x号和y号是否是朋友，若不是，则变成敌人
（2）询问x号的朋友有多少个
请你针对每个操作中的询问给出回答。
**/

/***
 * 借助所谓的分身　来完成　敌人与朋友的状态
 *
 * 将敌人与朋友区分开来　如果两个人有共同的敌人　也就是
 * find找到的共同祖先是一个　那么他们就是朋友
 * ***/
/***
int find(vector<int>& vec, int x)
{
    int r = x;
    while (r != vec[r])
        r = vec[r];
    return r;
}

int unite(vector<int>& vec, vector<int>& rank, int x_, int y_)
{
    int x = find(vec, x_);
    int y = find(vec, y_);

    if (x == y)
        return 0;
    if (rank[x] > rank[y])
        vec[y] = x;
    else 
    {
        vec[x] = y;
        if (rank[x] == rank[y])
            rank[x]++;
    }
        
    return 1;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> person(m, 0);
    vector<int> rank(m, 0);
    for (int i = 0; i < m; i++)
        person[i] = i;
    for (int i = 0; i != n; i++)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int x, y;
            cin >> x >> y;
            if (unite(person, rank, x, y) == 0)
                cout << "Y" << endl;
            else 
                cout << "N" << endl;
        }
        else if (ch == 2)
        {
            int x;
            int x_;
            int count = 0;
            cin >> x;
            int cmp = find(person, x);
            for (int i = 0; i != m; i++)
            {
                if (i != x)
                {
                    x_ = find(person, i); 
                    if (x_ == cmp)
                        count++;
                }
            }
            cout << count / 2 << endl;
        }
    }
}
大概能骗80%的答案　看一下acmer的写法
**/

/***
 *　关于所谓的分身　
 *  是将ｆ　也就是每个人的序号　都设置成自己　一直到2n
 *  a与a'的关系是敌人 
 *  举个栗子 当x与y find时不相同时 说明他们两个不是朋友
 *  那就需要将 x 与 y'建立联系表示 x与y是敌人 
 *  同时 将x' 与y建立联系 来表示x'与y是朋友
 *
 *
 *
 * ***/
  
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 300000 + 10;

int read()
{
    int f = 1, x = 0;
    char ch = getchar();
    if (ch == '-')
        f = -1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9')
    {
        x = x*10 + (ch-'0');
        ch = getchar();
    }
    return x*f;
}

int n, m, tp, x, y, f[2*maxn], size[2*maxn];

int getf(int n) 
{
    return f[n] == n ? n : f[n] = getf(f[n]);
}

void merge(int a, int b)
{
    int x = getf(a);
    int y = getf(b);
    if (x != y)
    { 
        f[y] = x;
        size[x] += size[y];
    }

    return ;
}

int main()
{
    n = read(); 
    m = read();

    for (int i = 1; i <= 2*n; i++)
        f[i] = i;

    for (int i = 1; i <= n; i++)
        size[i] = 1;

    while (m--)
    {
        tp = read();
        if (tp == 1)
        {
            x = read(); 
            y = read();
            if (getf(x) == getf(y))  //只需要判断x与y是否有相同的敌人
                printf("Y\n");
            else 
            {
                merge(x, y+n); 
                merge(y, x+n); 
                printf("N\n");
            }
        }
        else if (tp == 2)
        {
            x = read();
            printf("%d\n", size[getf(x)]-1);
        }
    }

    return 0;
}
