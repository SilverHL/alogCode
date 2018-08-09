#include <bits/stdc++.h>

using namespace std;

bool match(char *str, char *pattern)
{
    if (str[0] == '\0' && pattern[0] == '\0') 
        return true;
    if (str[0] != '\0' && pattern[0] == '\0')
        return false;

    if (*(pattern+1) != '*') {
        if (*(pattern+1) == '.' && str[0] != '\0') {
            return match(str+1, pattern+1);
        } else {
            if (str[0] == pattern[0])
                return match(str+1, pattern+1);
            else 
                return false;
        }
    } else {
        if (pattern[0] == str[0] || (*pattern == '.' && *str != '\0')) 
            return match(str+1, pattern) || match(str, pattern+2);
        else 
            return match(str, pattern+2);
    }
}
