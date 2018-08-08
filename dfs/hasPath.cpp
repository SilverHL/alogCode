#include <bits/stdc++.h>

using namespace std;

class Solution 
{
    int row;
    int col;
    char *mtx;
public:
    bool hasRightPath(int ri, int ci, int length, char *str, vector<bool> mark) 
    {
            if (length == strlen(str))
                return true;
        if (ri < 0 || ri >= row || ci < 0 || ci >= col)
            return false;

        cout << ri << " " << ci << " " << mtx[length] << endl;
        int index = ci + ri * col;
        bool res = false;

        if (!mark[index] && mtx[index] == str[length]) {
            mark[index] = true;
            res = hasRightPath(ri+1, ci, length+1, str, mark) ||
                        hasRightPath(ri-1, ci, length+1, str, mark) ||
                        hasRightPath(ri, ci+1, length+1, str, mark) ||
                        hasRightPath(ri, ci-1, length+1, str, mark);
        }        

        if (res) 
            return true;
        return false;
    }
    bool hasPath(char *matrix, int rows, int cols, char *str) 
    {
        if (str[0] == '\0') 
            return true;
        
        mtx = matrix;
        row = rows;
        col = cols;
        vector<bool> mark(strlen(matrix), false);

        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < cols; j++) 
                if (hasRightPath(i, j, 0, str, mark))
                    return true;

        return false;
    }
};

int main()
{
    Solution s;
    char *matrix = "ABCESFCSADEE";
    char *str = "ABCCED";
    cout << s.hasPath(matrix, 3, 4, str);
}
