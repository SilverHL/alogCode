/***
 * 牛牛很喜欢对数字进行比较，但是对于3 > 2这种非常睿智的比较不感兴趣。上了高中之后，学习了数字的幂，他十分喜欢这种数字表示方法，比如xy。
由此，他想出了一种十分奇妙的数字比较方法，给出两个数字x和y，请你比较xy和yx的大小，如果前者大于后者，输出">"，小于则输出"<"，等于则输出"="。

**/

#include <bits/stdc++.h>


using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int xx = 1;
    int yy = 1;
    for (int i = 0; i < x; i++)
        yy *= x;
    for (int i = 0; i < y; i++)
        xx *= y;

    if (xx == yy)
        cout << "=";
    else if (xx < yy)
        cout << ">";
    else 
        cout << "<";
}
