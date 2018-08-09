#include <iostream>

using namespace std;

int main()
{
    long long x, f, d, p;
    long long count = 0;

    cin >> x >> f >> d >> p;

    if (d < x) {
        cout << 0;
        return 0;
    }
    if (f * x == d) {
        cout << f ;
        return 0;
    }

    int i;

    if (f * x > d) {
        for (i = 0; i * x < d; i++);
        cout << i;
        return 0;
    }

    count += f;
    d -= f * x;

    for (int i = 0; (p + x) * i <= d; i++, count++ );

    cout << count;
    
    
}
