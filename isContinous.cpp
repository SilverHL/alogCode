#include <bits/stdc++.h>

using namespace std;

bool IsContinuous(vector<int> numbers)
{
    if (numbers.size() < 5) 
        return false;

    int len = numbers.size();
    int flag = 0;
    int min = 14;
    int max = -1;

    for (int i = 0; i < len; i++) {
        int number = numbers[i];
        if (number == 0)
            continue;
        if ((flag >> number) & 0x1) return false;
        flag |= (1 << number);
        if (number > max) max = number;
        if (number < min) min = number;
        if (max - min >= 5) return false;
    }

    return true;
}
