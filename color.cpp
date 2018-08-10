#include <iostream>
#include <memory.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int ans = 0, n, m, c, times, color, i, j;
    cin >> n >> m >> c;
    vector<int> vec[c+1];

    //按颜色分类
    for (i = 0; i < n; i++) 
    {
        cin >> times;
        for (int j = 0; j < times; j++) 
        {
            cin >> color;
            vec[color].push_back(i);
        }
    }

    //判断连续ｍ个是否出现重复
    //只需对每个颜色判断同颜色相邻的位置差是否小于ｍ
    for (int i = 1; i <= c; i++) 
    {
        //先判断环形头尾链接最后一个和第一个出现的位置差
        if (vec[i][0] + n - vec[i][vec[i].size()-1] < m) 
        {
            ans++;
            continue;
        }

        for (j = 0; j < vec[i].size()-1; j++) 
            if (vec[i][j+1] - vec[i][j] < m) 
            {
                ans++;
                break;
            }
    }

    cout << ans;
}
//优化空间复杂度
int ma()
{
    int ans = 0, n, m, c, times, color, i, j;
    cin >> n >> m >> c;
    int last_pos[c+1];
    int first_pos[c+1];
    bool ok[c+1];
    memset(last_pos, 0, sizeof(last_pos));
    memset(first_pos, 0, sizeof(first_pos));
    memset(ok, 1, sizeof(ok));

    for (int i = 1; i <= n; i++ )
    {
        cin >> times;
        for (j = 0; j < times; j++) 
        {
            cin >> color;
            if (ok[color])
            {
                if (!first_pos[color]) 
                    first_pos[color] = i;
                else if (i - last_pos[color] < m) 
                    ok[color] = false;
                last_pos[color] = i;
            }
        }
    }

    for (int i = 1; i <= c; i++) 
    {
        if (ok[i] && first_pos[i] + n - last_pos[i] < m) 
            ans++;
        if (!ok[i]) 
            ans++;
    }

    cout << ans;
}
