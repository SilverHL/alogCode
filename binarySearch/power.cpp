#include <bits/stdc++.h>

using namespace std;

double Power(double base, int ex) 
{
    int flag = 0;
    int n;
    if (ex > 0) {
        n = ex;
    } else if (ex < 0){
        if (base == 0) 
            return 0;
        n = -ex;  
    } else {
        return 1;
    }

    int res = 1;
    while (n) {
        if (n & 1) 
            res *= base;
        n >>= 1;
        base *= base;
    }

    return (ex > 0 ? res : (1/res));
   
}

int main()
{
    double a = 3.0;
    int b = 2;

    cout << Power(a, b);
}
