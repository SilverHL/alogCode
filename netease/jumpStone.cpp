/****
 * 小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，
小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 
小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
***/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        vector<int> steps(M+1, INT_MAX);
        steps[N] = 0;
        for (int i = N; i <= M; i++)
        {
            if (steps[i] == INT_MAX)
                continue;

            for (int j = 2; (j*j) <= i; j++) 
            {
                if (i % j == 0) 
                {
                    if (i + j <= M) 
                        steps[i+j] = min(steps[i]+1, steps[i+j]);
                    if (i + (i / j) <= M) 
                        steps[i+(i/j)] = min(steps[i]+1, steps[i+(i/j)]);
                }
            }
        }

        if (steps[M] == INT_MAX)
            cout << -1;
        else 
            cout << steps[M];

    }
}