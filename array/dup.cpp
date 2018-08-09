#include <bits/stdc++.h>

using namespace std;

bool duplicate(int numbers[], int length, int *dup)
{
    int map[length];
    memset(map, 0, sizeof(map));
    *dup = -1;
    for (int i = length-1; i >= 0; i++) {
        map[numbers[i]]++;
        if (map[numbers[i]] > 1) 
            *dup = numbers[i];
    }

    return *dup == -1;

}
