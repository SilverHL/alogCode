#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int apples[1000];
    int que[10000];
    int total[10000];
    
    memset(apples, 0, sizeof(apples));
    memset(que, 0, sizeof(que));
    memset(total, 0, sizeof(que));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> apples[i];
        if (i == 0)
            total[0] = apples[0];
        else 
            total[i] = total[i-1] + apples[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) 
        cin >> que[i];

    cout << total << endl;
    for (int i = 0; i < m; i++) 
    {
        if (find(total, total+m, que[i]) != total+m)
            cout << *lower_bound(total, total+m, que[i]) << endl;
        else 
            cout << find(total, total+m, que[i]) << endl;
    }
}
