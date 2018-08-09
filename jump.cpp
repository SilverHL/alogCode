#include <iostream>

using namespace std;

int getBig(int n, int m) 
{
    if (n > m) 
        swap(n, m);
    while (m % n != 0) 
    {
        m = n;
        n = m % n;
    }

    return n;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int res = 0;

    while (n < m)  
    {
        int i = getBig(n, m-n);
        n += i;
        res++;
    }

    if (n == m) 
        cout << res;
    else
        cout << -1;

}
