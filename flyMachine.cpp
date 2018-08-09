#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int h;
    cin >> h;

    int e = sqrt(h);
    int i;

    for (i = e; i >= 1; --i ) {
        if (i * i + i <= h)
            break;
    }

    return i;
        
}
