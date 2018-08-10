/**
 * 假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，
 * 形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 
 * 其中a的Index为0，aa的Index为1，aaa的Index为2，
 * 以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index. 
 * **/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1;
    cin >> str1;

    if (str1.length() != 4) 
    {
        if (str1[0] == 'a') 
        {
            cout << str1.length()-1 ;
            return 0;
        }
        else
        {
            int times = str1[0] - 'a' + 1;
        }

    }
}
