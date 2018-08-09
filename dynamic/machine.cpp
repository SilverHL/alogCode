
#include <bits/stdc++.h>

using namespace std;

#define NUM 10001

struct node {
    int x;
    int y;
}tk[NUM], mc[NUM];

int cmp(node a, node b)
{
    if (a.x == b.x) 
        return a.y > b.y;
    return a.x > b.x;
}

int main()
{
    int m, n;
    int mark[NUM];
    int count = 0;
    long long ans = 0;

    memset(mark, 0, sizeof(mark));
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> mc[i].x >> mc[i].y;

    for (int i = 0; i < m; i++) 
        cin >> tk[i].x >> tk[i].y;
    
    sort(tk, tk+m, cmp);
    sort(mc, mc+n, cmp);

    int i, j, k = 0;
    for (i = 0, j = 0; i < m; i++) {
        while (j < n && mc[j].x >= tk[i].x) {
            mark[mc[j].y]++;
            j++;
        }

        //从等级低的机器开始分配
        for (k = tk[i].y; k <= 100; k++) {
            if (mark[k]) {
                count++;
                mark[k]--;
                ans += 200 * tk[i].x + 3 * tk[i].y;
                break;
            }
        }
    }
    
    cout << count << " " << ans << endl;

}

