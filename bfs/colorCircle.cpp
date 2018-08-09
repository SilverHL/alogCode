#include <bits/stdc++.h>

using namespace std;

#define MAX 55

int n, m, flag;
char panel[MAX][MAX];
int mark[MAX][MAX];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct node 
{
    int x;
    int y;

    node(int _x, int _y) : x(_x), y(_y) {}
};

int main()
{
    cin >> n >> m;

    deque<node> deq;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> panel[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            deq.push_back(node(i, j));
            for (int index = 0; index < 4; index++) {
                int ni = 
            }
        }


}
