#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1001;
int n;
int balls[N];

int dfs(int pos, long long sum, long long pi)
{
    cout << pos << endl;
    int i, c;
    for (i = pos, c = 0; i < n; ++i) 
    {
        sum += balls[i];
        pi *= balls[i];
        if (sum > pi) //此时是可以的，并且能够继续向后搜索
            c += 1 + dfs(i+1, sum, pi);
        else if (balls[i] == 1) //可以进行后续搜索
            c += dfs(i+1, sum, pi);
        else        //剪枝 抛弃当sum < pi且后续数据都大于当前最后一个值 后的所有数据
            break;
        sum -= balls[i];
        pi /= balls[i];
        for ( ; i < n-1 && balls[i] == balls[i+1]; ++i );
    }

    return c;
}


int main()
{

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> balls[i];

    sort(balls, balls+n);
    cout << dfs(0, 0, 1);
}
