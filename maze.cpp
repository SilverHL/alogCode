#include <bits/stdc++.h>

using namespace std;

#define VISITED 2

int maze[10][10];
int cost[4] = {-3, -1, -1, 0};
int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
int m, n, p; 
int final_p = -1000;

struct position {
    int x;
    int y;
    position(int vx, int vy) : x(vx), y(vy) {} 
};

vector<position> pathStack;
vector<position> minCostPath;

void search(int x, int y, int cur_p)
{
    maze[x][y] = VISITED;
    pathStack.push_back(position(x, y));

    if (x == 0 && y == m-1 && cur_p >= 0) {
        if (cur_p > final_p) {
            final_p = cur_p;
            minCostPath = pathStack;
        }
        pathStack.pop_back();
        maze[x][y] = 1;
        return;
    }

    if (cur_p > 0) {
        for (int i = 0; i < 4; i++) {
            int nx = dir[i][0] + x;
            int ny = dir[i][1] + y;
            int np = cur_p + cost[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1) 
                search(nx, ny, np);
        }
    }

    pathStack.pop_back();
    maze[x][y] = 1;

}

void printPath(vector<position> &path)
{
    for (int i = 0; i < path.size(); i++) {
        cout << "[" << path[i].x << "," << path[i].y << "]";
        if (i < path.size() - 1) 
            cout << ",";
    }
}


int main()
{
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> maze[i][j];

    search(0, 0, p);

    if (final_p == -1000) 
        cout << "Can not escape!" ;
    else 
        printPath(minCostPath);

}
