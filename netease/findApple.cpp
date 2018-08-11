#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int que[10000];
    int total[10000];
    int tmp;
    
    memset(total, 0, sizeof(que));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (i == 0)
            total[0] = tmp;
        else 
            total[i] = total[i-1] + tmp;
    }

    cin >> m;
    for (int i = 0; i < m; i++) 
    {
        cin >> tmp;
        int pos = lower_bound(total, total + n, tmp) - total;
        cout << pos+1 << endl;
    }

}
