#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    vector<int> v(n, 0);
    int count1 = 0, count2 = 0;
    int flag = 1;
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    sort(v.begin(), v.end());

    for (auto rb = v.rbegin(); rb != v.rend(); rb++) {
        if (flag) 
            count1 += *rb;
        else 
            count2 += *rb;
        flag = (flag == 1 ? 0 : 1);
    }

    cout << count1 - count2 << endl;;

}
