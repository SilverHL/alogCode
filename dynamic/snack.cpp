#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans = 0;
ll sum = 0;
    
int num, weight;
vector<int> v(num, 0);

void dfs(int t, ll sum)
{
    ans++;
    if (t == num-1)
        return;

    for (int i = t+1; i < num; i++) 
        if (sum+v[i] <= weight)
            dfs(i, sum+v[i]);

}


int main()
{   

    cin >> num >> weight;

    for (int i = 0; i < num; i++) {
        cin >> v[i];
        sum += v[i];
    }

    if (sum < weight) 
        ans << num;
    else 
        dfs(-1, 0);


}
