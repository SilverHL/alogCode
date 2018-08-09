#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 100;
int a[N], b[N], visit[N];
int c[15];

int judge(int n, int k, int b[])
{
    int res = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = i+1; j <= n; j++) 
            if (b[i] < b[j]) 
                res++;
    return res == k;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];        
        visit[a[i]] = 1;
    }

    int total = 0;
    for (int i = 1; i <= n; i++ ) 
    {
        if (visit[i] == 0) 
            c[total++] = i;
    }

    int index[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    do {
        int idx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0) {
                b[i] = c[index[idx++]];
            } else {
                b[i] = a[i];
            }
        }
        if (judge(n, k, b)) 
            ans++;
        for (int i = 0; i <= n; i++) 
            cout << index[i];
        cout << endl;
    } while (next_permutation(index, index+total));
    cout << ans;
}

