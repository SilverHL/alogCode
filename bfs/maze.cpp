#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

char a[1010][1010];
int vis[1010][1010];
struct Point
{
    int x, y;
    Point(int x_, int y_) : x(x_), y(y_) {}
    Point() {}
} tmp1, tmp2;

int mt[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

queue<Point> q;
int main()
{
    int n, i, j;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        int sx, sy;
        int ex, ey;
        int flag = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
            {
                vis[i][j] = 0;
                if (a[i][j] == 'S') 
                {
                    sx = i;
                    sy = j;
                }
                else if (a[i][j] == 'E')
                {
                    ex = i;
                    ey = j;
                }
            }
        while (!q.empty()) 
            q.pop();

        tmp1.x = sx;
        tmp1.y = sy;
        vis[sx][sy] = 1;
        q.push(Point(sx, sy));
        while (!q.empty()) 
        {
            tmp1 = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                tmp2.x = mt[i][0] + tmp1.x;
                tmp2.y = mt[i][1] + tmp1.y;
                if (tmp2.x >= 0 && tmp2.x < n && 
                    tmp2.y >= 0 && tmp2.y < n && 
                    a[tmp2.x][tmp2.y] != '#' &&
                    !vis[tmp2.x][tmp2.y]) 
                {
                    vis[tmp2.x][tmp2.y] = vis[tmp1.x][tmp1.y] + 1;
                    q.push(tmp2);
                }
                    
            }

            if (vis[ex][ey]) 
            {
                flag = 1;
                break;
            }
        }

        if (flag) 
            cout << vis[ex][ey] - 1 << endl;
        else 
            cout << -1 << endl;
    }
}
