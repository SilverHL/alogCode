#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sum;
    int res = 0;
    
    cin >> sum;

    int r = sqrt(sum);
    if (sum == r * r)
        res += 4;
    for (int i = sum-1; i > 0; --i) 
    {
        r = sqrt(i);
        if (r * r == i) 
        {
            r = sqrt(sum - i);
            if (r * r == sum - i) {
                res += 4;
            }
        }
    }

    cout << res;
}
