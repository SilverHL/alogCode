/***
 * n*m的网格 给定位置和开灯关灯的时间
 * 问哪个时刻的灯开的最多
 * 排序 遍历一遍 记录最大值
 * **/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>

using namespace std;

const int MAXN = 555;
const int MAXK = 1e5+1;

int n, m, k;
int cnt[MAXN][MAXN];
int tag[MAXN][MAXN];

struct engineer
{
    int x, y, z;
    int HH, MM;
    double SS;
}eng[MAXK];


bool cmp(const engineer &A, const engineer &B)
{
    if (A.HH != B.HH)
        return A.HH < B.HH;
    else if (A.MM != B.MM)
        return A.MM < B.MM;
    else 
        return A.SS < B.SS;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> eng[i].x >> eng[i].y >> eng[i].z ;
        scanf("%d:%d:%lf", &eng[i].HH, &eng[i].MM, &eng[i].SS);
    }

    sort(eng, eng+k, cmp);
    int c = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (eng[i].z)
            cnt[eng[i].x][eng[i].y]--;
        else 
            cnt[eng[i].x][eng[i].y]++;

        if (cnt[eng[i].x][eng[i].y] == 0)
            c--;
        else if (cnt[eng[i].x][eng[i].y] == 1)
        {
            c++;
            if (c >= ans)
            {
                ans = c;
                memcpy(tag, cnt, sizeof(cnt));
            }
        }
    }
}
