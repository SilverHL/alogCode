#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    string table = "0123456789ABCDEF";
    string res;
    cin >> n >> m;

    if (n < 0) {
        n = -n;
        cout << "-";
    }

    while (n) {
        res = table[n%m] + res;
        n /= m;
    }

    cout << res;

}
