#include <bits/stdc++.h>

using namespace std;

struct point
{
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}
    point operator+(const point &rhs) const
    { return point(x + rhs.x, y + rhs.y); }
    point operator-(const point &rhs) const
    { return point(x - rhs.x, y - rhs.y); }
    point rotate() {return point(-x, y); }
    point rotate(const point &o) const { return o + (*this - o).rotate(); }
    bool operator==(const point &rhs) const 
    { return x == rhs.x && y == rhs.y; }
};

bool check(const point &a, const point &b)
{
    if (a.x == 0 && a.y == 0 ||
        b.x == 0 && b.y == 0)
        return false;
    if (a.x * a.x + a.y * a.y != 
            b.x * b.x + b.y * b.y)
        return false;
    if (a.x * b.x + a.y * b.y != 0)
        return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        point p[4], o[4], a[4];
        for (int i = 0; i < 4; i++)
            cin >> p[i].x >> p[i].y >> o[i].x >> o[i].y;
        int res = -1;
        int x, y, z, w;
        for (x = 0, a[0] = p[0]; x < 4; x++)
            for (y = 0, a[1] = p[1]; y < 4; y++) 
                for (z = 0, a[2] = p[2]; z < 4; z++)
                    for (w = 0, a[3] = p[3]; w < 4; w++)
                    {
                        int cost = x + y + z + w;
                        if (a[0] + a[1] == a[2] + a[3] && 
                                check(a[0] - a[1], a[2] - a[3]) ||
                            a[0] + a[2] == a[1] + a[3] && 
                                check(a[0] - a[2], a[1] - a[3]) ||
                            a[0] + a[3] == a[1] + a[2] &&
                                check(a[0] - a[3], a[1] - a[2]))
                            if (res == -1 || res > cost)
                                res = cost;

                    }
    }
}
