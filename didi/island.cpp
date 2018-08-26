/***
 * 给定一个m行n列的二维地图, 初始化每个单元都是水.
操作addLand 把单元格(row,col)变成陆地.
岛屿定义为一系列相连的被水单元包围的陆地单元, 横向或纵向相邻的陆地称为相连(斜对角不算).
在一系列addLand的操作过程中, 给出每次addLand操作后岛屿的个数.
二维地图的每条边界外侧假定都是水.
***/

#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

/**
int island[100][100];
int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int row;
int line;
int main()
{
    int op;
    int count = 0;

    memset(island, 0, sizeof(island));
    cin >> row >> line >> op;
    for (int i = 0; i < op; i++)
    {
        int r, l;
        int flag = 0;
        cin >> r >> l;
        if (r < 0 || r >= row || 
            l < 0 || l >= line || island[r][l])
        {
            cout <<  count << " ";
            continue;
        }

        for (int index = 0; index < 4; index++)
        {
            int nr = r + dir[index][0];
            int nl = l + dir[index][1];

            if (nr >= 0 && nr < row && 
                nl >= 0 && nl < line)
            {
                if (island[nr][nl] == 0)
                    continue;
                else if (island[nr][nl] == 1)
                {
                    flag = 1;
                    island[nr][nl] = 2;
                    break;
                }
                else 
                {
                    count--;
                }
            }
        }

        if (flag == 0)
            count++;
        island[r][l] = 1;
        cout << count << " ";

    }


}
**/

int find(vector<int>& par, int x)
{
    int tmp = x;
    while (tmp != par[tmp])
        tmp = par[tmp];
    return tmp;
}

int unite(vector<int>& par, vector<int>& rank, int r, int l)
{
    int x = find(par, r);
    int y = find(par, l);

    if (x == y)
        return 0;
    if (rank[x] > rank[y])
        par[y] = x;
    else 
    {
        par[x] = y;
        if (rank[x] == rank[y])
            rank[x]++;
    }

    return 1;
}

int main()
{
    int row, line, k;
    cin >> row >> line >> k;

    vector<vector<int> >map(row, vector<int>(line, 0));
    vector<int> par(k, 0);
    vector<int> rank(k, 0);
    int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < k; i++)
        par[i] = i;
    int count = 0, id = 1;
    for (int i = 0; i != k; i++)
    {
        int r, l;
        vector<int> landid;
        cin >> r >> l;
        if (r < 0 || r >= row ||
            l < 0 || l >= line || 
            map[r][l] != 0)
        {
            cout << count << " ";
            continue;
        }

        for (int index = 0; index != 4; index++)
        {
            int nr = r + dir[index][0];
            int nl = l + dir[index][1];
            if (nr >= 0 && nr < row && 
                nl >= 0 && nl < line)
                if (map[nr][nl] != 0)
                    landid.push_back(map[nr][nl]);
        }

        if (landid.empty())
        {
            map[r][l] = id++;
            count++;
        }
        else 
        {
            map[r][l] = landid[0];
            for (auto i : landid)
                count -= unite(par, rank, landid[0], i);
        }

        cout << count << " ";
    }
}
