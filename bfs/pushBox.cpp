#include <iostream>
#include <queue>

using namespace std;

int m, n;
char maze[10][10];
int vis[10][10][10][10];
int px, py, bx, by, ex, ey;
int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};

struct Step
{
    int px, py, bx, by;
    Step(int px_, int py_, int bx_, int by_) :
            px(px_), py(py_), bx(bx_), by(by_) {}
};


int bfs()
{
    Step s(px, py, bx, by);
    queue<Step> que;
    que.push(s);

    while (!que.empty()) 
    {
        s = que.front();
        que.pop();

        if (s.bx == ex && s.by == ey) 
            return vis[s.px][s.py][s.bx][s.by];
        for (int i = 0; i < 4; i++) 
        {
            int nx = s.px + dir[i][0];
            int ny = s.py + dir[i][1];
            if (nx < 0 || nx >= n ||
                ny < 0 || ny >= m ||
                maze[nx][ny] == '#')
                continue;
            if (nx == s.bx && ny == s.by) 
            {
                if (nx + dir[i][0] < 0 ||
                    ny + dir[i][1] < 0 ||
                    nx + dir[i][0] >= n ||
                    ny + dir[i][1] >= m || 
                    maze[nx+dir[i][0]][ny+dir[i][1]] == '#')
                    continue;
                if (vis[nx][ny][nx+dir[i][0]][ny+dir[i][1]])
                    continue;
                vis[nx][ny][nx+dir[i][0]][ny+dir[i][1]] = 
                    vis[s.px][s.py][s.bx][s.by] +1;
                que.push(Step(nx, ny, nx+dir[i][0], ny+dir[i][1]));
            } else 
            {
                if (vis[nx][ny][s.bx][s.by])
                    continue;
                vis[nx][ny][s.bx][s.by] = 
                    vis[s.px][s.py][s.bx][s.by] + 1;
                que.push(Step(nx, ny, s.bx, s.by));
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'X')
                px = i, py = j;
            if (maze[i][j] == '*')
                bx = i, by = j;
            if (maze[i][j] == '@')
                ex = i, ey = j;
        }
    vis[px][py][bx][by] = 1;
    cout << bfs();
}
