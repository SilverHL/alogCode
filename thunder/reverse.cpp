#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    if (n < 0)
    {
        cout << "-";
        n = -n;
    }

    int firstFlag = 1;
    while (n)
    {
        if (n % 10 != 0)
            firstFlag = 0;
        if (firstFlag == 0)
            cout << (n % 10);
        n /= 10;

    }
}
