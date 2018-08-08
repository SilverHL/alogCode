#include <bits/stdc++.h>

using namespace std;

#define MAX 100


int row;
int col;
int counter;

int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int mark[MAX][MAX];

int getCost(int r, int c) 
{
    int cost = 0;
    cost += r%10;
    cost += r/10;
    cost += c%10;
    cost += c/10;
    return cost;
}

void moving(int m, int ri, int ci)
{
    mark[ri][ci] = 1;

    for (int i = 0; i < 4; i++) {
        int nri = ri + dir[i][0];
        int nci = ci + dir[i][1];
        int cost = getCost(nri, nci);
        if (!mark[nri][nci] && 
            nri >= 0 && nri < row && 
            nci >= 0 && nci < col && 
            cost <= m) 
        {
            cout << ri << " " << ci  << endl;
            counter++;
            moving(m, nri, nci);
        }
    }
}

int movingCount(int m, int rows, int cols)
{
    if (m <= 0)
        return 0;

    row = rows;
    col = cols;
    counter = 1;
    
    int mark[MAX][MAX];
    moving(m, 0, 0);
    return counter;
}


int main()
{
    movingCount(15, 20, 20);
    cout << counter << endl;
}
