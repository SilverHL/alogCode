#include <bits/stdc++.h>

using namespace std;

int maxSubMatrix(vector<vector<int> > matrix,
                 int n, int m)
{
    int base_sum = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            base_sum  += matrix[i][j];

    int result = 0;
    for (int i = 0; i+n < matrix.size(); i++) {
        if (i > 1) 
            for (int y = 0; y < m; y++) 
                base_sum += (matrix[i+n][y] - matrix[i-1][y]);

        int real_sum = base_sum;
        if (real_sum > result) 
            result = real_sum;

        for (int j = 0; j+m < matrix[0].size(); j++) 
            if (j > 1)
                for (int x = 0; x < n; x++) 
                    real_sum += matrix[x][j+m] - matrix[x][j-1];
        if (real_sum > result) 
            result = real_sum;
    }

    return result;
}
