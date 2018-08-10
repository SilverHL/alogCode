/***
 * 读入一个字符串str，输出字符串str中的连续最长的数字串
 * */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1;
    int cnt = 0;
    int tmp = 0;
    int pos;

    cin >> str1;

    for (int i = 0; i < str1.length(); i++) 
    {
        if (str1[i] >= '0' && str1[i] <= '9') 
        {
            int j = i;
            while (j < str1.length() && 
                   str1[j] >= '0' && 
                   str1[j] <= '9')
            {
                tmp++;
                j++;
            }

            if (tmp > cnt)
            {
                cnt = tmp;
                pos = i;
            }

            tmp = 0;
            i = j;
        }
    }

    for (int i = 0; i < cnt; i++)
        cout << str1[pos++];

    return 0;
}
