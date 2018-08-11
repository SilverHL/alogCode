#include <bits/stdc++.h>

using namespace std;

int row, line;
char maze[100][100];
int mark[100][100];
string word;
int counter = 0;
int dir[8][2] = {0, 1, 1, 0, 1, 1};

void dfs(int i, int j)
{
    mark[i][j] = 1;
    int ti = i;
    int tj = j;
    if (maze[i][j] == word[0])
    {
        for (int d = 0; d < 3; d++) 
        {
            int idx;
            for (idx = 1; idx < word.length(); idx++)
            {
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];
//                cout << ni << " " << nj << " " << maze[ni][nj] << endl;
                if (ni >= 0 && ni < row &&
                    nj >= 0 && nj < line &&
                    mark[ni][nj] == 0 &&
                    maze[ni][nj] == word[idx])
                {
                    mark[ni][nj] = 1;
                    i = ni;
                    j = nj;
                } else 
                {
                    i = ti;
                    j = tj;
                    break;
                }
            }

            if (idx == word.length()) 
            {
                counter++;
  //              cout << "find: " << d << " " << maze[i][j] << endl;
                i = ti;
                j = tj;
                continue;
            }
        }
    }
}

int main()
{
    int n;
    int index = 0;
    cin >> n;

    while (n--)
    {   
        cin >> row >> line;
        memset(maze, 0, sizeof(maze));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < line; j++)
                cin >> maze[i][j];
        cin >> word;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < line; j++)
            {
                memset(mark, 0, sizeof(mark));
                dfs(i, j);
            }
        cout << counter << endl;
        counter = 0;
        word.clear();
    }

}
