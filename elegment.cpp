/***
 * 很暴力了
 * 大象从圆中的一点到达另外一点 到达边界处可到原点对称的位置
 * 求最短距离 直接枚举
 * **/
#include <math.h>
#include <iostream>

using namespace std;

const double ESP = 1e-3;
const double CIR = 360;
const double PI = 3.1415926;

int r;
double x, y, xx, yy;

double dis(double x, double y, double x1, double y1)
{
    return sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
}

int main()
{
    cin >> r;
    cin >> x >> y;
    cin >> xx >> yy;

    double ans = dis(x, y, xx, yy), x_, y_;
    for (double i = 0; i <= CIR; i += ESP)
    {
        x_ = r * cos((i * PI / 180));
        y_ = r * sin((i * PI / 180));
        ans = min(ans, dis(x, y, x_, y_) + dis(xx, yy, -x_, -y_));
    }
    cout << ans;
}
