#include <bits/stdc++.h>

using namespace std;

int isBit(int a, int index)
{
    a >>= index;
    if (a & 0x1) 
        return 1;
    else 
        return 0;
}

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    
    int res = data[0];
    
    for (int i = 1; i < data.size(); i++) {
        res ^= data[i];
    }

    int count = 0;
    while (res & 0x1 == 0) {
        res >>= 1;
        count++;
    }

    *num1 = 0, *num2 = 0;
    for (int i = 0; i < data.size(); i++) {
        if (isBit(data[i], count)) 
            *num1 ^= data[i];
        else 
            *num2 ^= data[i];
    }
}
