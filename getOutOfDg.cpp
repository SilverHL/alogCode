#include <bits/stdc++.h>

using namespace std;

struct Step
{
    int x;
    int y;
};

Step step[51];
char dg[51][51];
int mark[51][51];
bool lev = false;
int n, m, x, y, k;

bool isClear(int x, int y, 
             int nx, int ny)
{
    bool res1 = true;
    bool res2 = true;
    {
        for (int i = x; i <= nx; i++) 
            if (dg[i][y] == 'X')
                res1 = false;
        for (int j = y; j <= ny; j++)
            if (dg[nx][j] == 'X')
                res1 = false;
    }

    {
        for (int j = y; j <= ny; j++) 
            if (dg[x][j] == 'X')
                res2 = false;
        for (int i = x; i <= nx; i++)
            if (dg[i][ny] == 'X')
                res2 = false;
    }

    return res1 | res2;
}

void moving(int x, int y, int num) 
{
    mark[x][y] = num;

    cout << "current path : " << x << " " << y << " " << endl;

    for (int i = 0; i < k; i++) {
        int nx = step[i].x + x;
        int ny = step[i].y + y;
        if (nx >= 0 && nx < n && 
            ny >= 0 && ny < m &&
            mark[nx][ny] > num+1) 
            if (isClear(x, y, nx, ny))
                moving(nx, ny, num+1);
    }
}

int main()
{
    int res = -1;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> dg[i][j];
    cin >> x >> y >> k;
    for (int i = 0; i < k; i++)
        cin >> step[i].x >> step[i].y;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mark[i][j] = INT_MAX;
    moving(x, y, 0);
        
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mark[i][j] != INT_MAX && mark[i][j] > res)
                res = mark[i][j];

    cout << res;
    return 0;
}
