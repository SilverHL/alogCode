/***
 * 东东对幂运算很感兴趣,在学习的过程中东东发现了一些有趣的性质: 9^3 = 27^2, 2^10 = 32^2
东东对这个性质充满了好奇,东东现在给出一个整数n,希望你能帮助他求出满足 a^b = c^d(1 ≤ a,b,c,d ≤ n)的式子有多少个。
例如当n = 2: 1^1=1^1
1^1=1^2
1^2=1^1
1^2=1^2
2^1=2^1
2^2=2^2
一共有6个满足要求的式子
**/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
set<int> S;
int n;
int main() {
    cin >> n;
    int res = 1LL * n * (n * 2 - 1) % mod;
    for(int i = 2; i * i <= n; i++) 
    {
        if(S.find(i) != S.end()) 
            continue;
        long long tmp = i;
        int cnt = 0;
        while(tmp <= n) 
        {
            S.insert(tmp);
            tmp = tmp * i;
            cnt++;
        }
        for(int i = 1; i <= cnt; i++) 
            for(int j = i + 1; j <= cnt; j++) 
                res = (res + n / (j / __gcd(i, j) ) * 2LL ) % mod;
    }
    cout << res << endl;
    system("pause");
    return 0;
}
