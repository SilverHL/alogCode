/***
 * 对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。例如:
如果 X = 123，则rev(X) = 321;
如果 X = 100，则rev(X) = 1.
现在给出整数x和y,要求rev(rev(x) + rev(y))为多少？
***/

#include <bits/stdc++.h>

using namespace std;

int recv(int x)
{
    int res = 0;
    while (x)
    {
        res += x%10;
        x /= 10;
        if (x == 0)
            break;
        res *= 10;
    }

    return res;
}

int main()
{
    int x, y;
    cin >> x >> y;

    int x1 = recv(x);
    int y1 = recv(y);

    cout << recv(x1+y1);
}
