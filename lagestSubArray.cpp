#include <bits/stdc++.h>

using namespace std;

#define MAX 1000010
int main()
{
    int n;
    vector<int> v(MAX, 0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    
    int max = v[0];
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (max + v[i] < 0) 
            max = 0;
        else {
            if (max + v[i] > res)
                res = max + v[i];
        }
    }

    cout << res;
}
