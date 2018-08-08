#include <bits/stdc++.h>

using namespace std; 
#define MAX 55

int flag = 0;
int n, m;

char panel[MAX][MAX];
int mark[MAX][MAX];

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void dfs(int x,int y, int step){
    cout << x << " " << y << endl;
    mark[x][y] = step;
    for(int i = 0;i < 4; ++i){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(panel[x][y] == panel[nx][ny]){
           if(mark[x][y] - mark[nx][ny] >= 3 && mark[nx][ny] != 0){
               flag = 1;
               return;
           } else if(mark[nx][ny] == 0){
               dfs(nx, ny, step+1);
           }
        }
    }
}


int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)  
            cin >> panel[i][j];
        


    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < m; j++) { 
            if(mark[i][j] != 0) continue;
            dfs(i, j, 1);
            if(flag == 1){
                cout << "Yes";return 0;
            }
        }
    }
    cout << "No";
}
