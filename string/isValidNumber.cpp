#include <bits/stdc++.h>

using namespace std;

bool isNumeric(char *str)
{
    if (str == NULL || str[0] == '\0')
        return false;

    bool sFlag = 0;
    bool eFlag = 0;
    bool pFlag = 0;
    int i = 0;
    int len = strlen(str);

    if (str[0] == '+' || str[0] == '-') {
        sFlag = 1;
        ++i;
    }

    for (; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') 
            continue;
        else if (str[i] == '.' && !pFlag) { 
            pFlag = 1;
            continue;
        }
        else if (str[i] == )

    }
}
