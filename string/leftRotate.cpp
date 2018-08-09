#include <bits/stdc++.h>

using namespace std;

string LeftRotateString(string str, int n)
{
    int len = str.length();
    string newstr = str + str;
    string res;

    for (int i = 0; i < len; i++, n++) {
        res = res + newstr[n];
    }

    return res;
    
}
