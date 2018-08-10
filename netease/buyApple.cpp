/**
 * 小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。 
 * 可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。
 * **/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n+1, INT_MAX);
    vec[0] = 0;

    for (int i = 0; i < n; i++)
    {
        if (vec[i] == INT_MAX)
            continue;
        if (i + 6 <= n) 
            vec[i+6] = min(vec[i]+1, vec[i+6]);

        if (i + 8 <= n)
            vec[i+8] = min(vec[i]+1, vec[i+8]);

        if (i + 6 > n || i + 8 > n ) 
            break;
        
    }

    if (vec[n] == INT_MAX)
        cout << -1;
    else 
        cout << vec[n];
    
}
