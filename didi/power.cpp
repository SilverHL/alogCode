/***
 * 给定两个数R和n，输出R的n次方，其中0.0<R<99.999, 0<n<=25
 * **/

/***
 * 快速幂 根据幂的二进制最后一位判断 是否应该相乘来 
 * 然后每次将二进制右移一位并且将 x自己乘一次与幂相对 
 * **/
#include <iostream>

using namespace std;

int main()
{
    long  double x;
    
    int num;

    while (scanf("%Lf %d", &x, &num) == 2)
    {
        long double res = 1;
        while (num != 0)
        {
            if (num & 0x1)
                res *= x; 
            x *= x;
            num >>= 1;
        }
        
        printf("%9.99Lf", res);
    }
}
