#include <iostream>

using namespace std;

const int mod = 1e9+7;

int main()
{
    long long dis;
    cin >> dis;

    long long times = 4;
    int ans = 100001;
    for (int i = 1; i < 300000; ++i) {
        int x = ((long long)(i) * times + times - 1) % mod ;
        if (x == 0) {
            ans = (i + 1) / 3 + 
                    (i + 1) % 3 ? 1 : 0;
            break;
        }

        times = times * 2;
    }

    cout << (ans > 100000 ? -1 : ans);
}
