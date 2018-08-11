#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int high;
    int index;
};

bool cmp(Node n1, Node n2)
{
    return n1.high < n2.high;
}

int main()
{
    int n, k;
    Node high[101];
    int mx = 0, mn = INT_MAX;
    int total = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
    {
        cin >> high[i].high;
        high[i].index = i+1;
        total += high[i].high;
    }

    sort(high, high+n, cmp);
    
    int i = 0, j = n-1;
    int avge = total / n;

    if (total % n == 0 && k >= total / n)
    {
        cout << 0 << " " << total/n << endl;
        k = total / n;
    }
    else 
    {
        cout << total - avge*n << " " << k << endl;
    }
    while (k && i <= j)
    {
        while (high[i].high < avge && high[j].high > avge)
        {
            high[i].high++;
            high[j].high--;
            --k;
            cout << high[j].index << " " << high[i].index << endl;
        }

        if (high[i].high == avge)
            i++;
        if (high[j].high == avge)
            j--;

    }
    return 0;
}
