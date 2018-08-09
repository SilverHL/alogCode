#include <iostream>
#include <vector>

using namespace std;

typedef  long long ll;

int main()
{
    int n;
    int k, d;
    int stu[n+1];
    
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> stu[i];
    cin >> k >> d;

    int dp_max[n+1][k+1];
    int dp_min[n+1][k+1];

    for (int i = 0; i < n; i++) 
        dp_max[i][1] = dp_min[i][1] = 0;

    for (int i = 0; i < n; i++) 
        for (int j = 2; j <= k; j++) 
            for (int m = max(0, i-d); m < i-1; m++) {
                dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j-1] * stu[i], dp_min[m][j-1] * stu[i]));
                dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j-1] * stu[i], dp_max[m][j-1] * stu[i]));
            }

    ll res = 0;
    for (int i = 0; i < n; i++) 
        if (dp_max[i][k] > res)
            res = dp_max[i][k];

    return res;
    
}
