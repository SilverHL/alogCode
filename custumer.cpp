#include <bits/stdc++.h>

using namespace std;

#define CusNum 50010

struct node 
{
    int num;
    int money;
} cus[CusNum];

int cmp(node a, node b)
{
    if (a.money == b.money) 
        return a.num > b.num;
    return a.money > b.money;
}

int main()
{
    int n, m;
    vector<int> table(50000, 0);
    int mark[CusNum];
    int sum = 0;

    memset(mark, 0, sizeof(mark));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> table[i];

    for (int i = 0; i < m; i++) {
        cin >> cus[i].num;
        cin >> cus[i].money;
    }

    sort(table.rbegin(), table.rend());
    sort(cus, cus+m, cmp);
    
    int i, j, k;
    int max = 0;
    for (int i = 0; i < n; i++) {
        mark[table[i]]++;
        if (table[i] > max) 
            max = table[i];
    }
    for (i = 0; i < m; i++) {
        for (j = cus[i].num; j <= max; j++) 
            if (mark[j]) {
                mark[j]--;
                sum += cus[i].money;
                break;
            }
    }

    cout << sum;
}
