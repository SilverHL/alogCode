#include <bits/stdc++.h>

using namespace std;

int Add(int n1, int n2)
{
    while (n2 != 0) {
        int temp = n1 ^ n2;
        n2 = (n1 & n2) << 1;
        n1 = temp;
    }

    return n1;

}
