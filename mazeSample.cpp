#include <bits/stdc++.h>

using namespace std;

#define VISITED 2

int m, n, p;
int maze[10][10];
int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int cost[4] = {-1, -1, 3, 0};
int final_p = -200; //剩余的体力值

struct position 
{
    int x, y;
    position(int vx, int vy) : x(vx), y(vy) {}
};

//存储每次遍历到的路径
vector<position> pathStack;
//存储最终的最优路径
vector<position> minCostPath;

void printPath(const vector<position>& path)
{
    for (int i = 0; i < path.size(); i++) {
        cout << "[" << path[i].x << ", " << path[i].y << "]";
        if ( i < path.size()-1) 
            cout << ",";
    }
}

void search(int x, int y, int cur_p) 
{
    //将当前点加入路径并且标记为VISITED 
    pathStack.push_back(position(x, y));
    maze[x][y] = VISITED;

    //如果当前点是出口 更新final_p 和 minCostPath 
    if (x == 0 && y == m-1 && cur_p >= 0) {
        if (cur_p > final_p) {
            final_p = cur_p;
            minCostPath = pathStack;
        }
        pathStack.pop_back();
        maze[x][y] = 1;
        return;
    }

    //如果当前节点不是出口点并且体力值>=0 分别向上下左右四个方向探索 计算相应的体力值
    if (cur_p >= 0) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            int np = cur_p + cost[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 1) 
                search(nx, ny, np);
        }
    }

    pathStack.pop_back();
    maze[x][y] = 1;
}


int main()
{
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> maze[i][j];

    search(0, 0, p);
    if (final_p != -200) 
        printPath(minCostPath);
    else 
        cout << "Can not escape!" ;

}
