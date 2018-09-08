/***
 * 给出n个数字 a_1,...,a_n，问最多有多少不重叠的非空区间，使得每个区间内数字的xor
 * 都等于0。即找出最大的k，使得存在k个区间(l[i], r[i])，满足1<=l[i]<=r[i]<=n (1<=i<=k), 
 * r[i]<l[i+1](1<=i<k), 且 a[l[i]] xor a[l[i]+1] xor... xor a[r[i]] = 0 (1<=i<=k)
 * **/


#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, bool> M;
    M[0]++;
    int ans = 0;
    int res = 0;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        res ^= tmp;
        if (M[res])
        {
            ans++;
            M.clear();
        }
        M[res] = true;
    }
    cout << ans << endl;
}
