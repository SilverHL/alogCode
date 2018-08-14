/***
 * 说一下我自己理解的看毛片算法
 *
 * 这个算法出现主要就是为了减少字符串与子串不匹配时
 * 回溯的距离可以尽可能减少
 * 也就是通过已经成功匹配的子串中 首尾对称的子串 
 * 就可以跳过匹配这一段重复的子串 从k+1开始匹配
 * i回到i-k j回到k-1
 * 从i-k 到 i-1这段 以及 j-k 到 j-1 这段
 * 以及 i-j到 i-j+k 以及 0~k-1这段都是一样的
 * **/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GetNextVal(string p, vector<int>& next)
{
    int len = p.length();
    next.resize(p.length());
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < len - 1)
    {
        if (k == -1 || p[j] == p[k])
        {
            ++j;
            ++k;

            if (p[j] != p[k])
                next[j] = k;
            else 
                next[j] = next[k];
        } 
        else 
        {
            k = next[k];
        }
    }
}

int KMPSearch(string s, string p)
{
    int i = 0;
    int j = 0;
    int sLen = s.length();
    int pLen = p.length();
    vector<int> next;
    GetNextVal(p, next);

    while (i < sLen && j < pLen)
    {
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else 
        {
            //如果j不为-1且当前匹配字符失败 就让j指向最大相同前缀串的后一个 即next[j]
            j = next[j];
        }
    }

    if (j == pLen)
        return i - j;
    else 
        return -1;
}
