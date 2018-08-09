#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int main()
{
    int kiddo[100];
    int num = 0;
    int temp;
    int total = 0;

    memset(kiddo, 0, sizeof(kiddo));
    while (cin >> temp) {
        kiddo[num++] = temp;
    }

    sort(kiddo, kiddo+num);

    for (int i = 0; i < num; i++) 
    {
        if (kiddo[i] == 0) 
        {
            total++;
            continue;
        }

        if (kiddo[i] == kiddo[i+1]) 
        {
            total += kiddo[i] + 1;
            i++;
            continue;
        } 

        total += kiddo[i] + 1;
    }

    cout << total;
}
