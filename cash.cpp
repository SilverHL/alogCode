#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int cash[20];
    int miss = 0;

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> cash[i];

    sort(cash, cash+n);
    for (int i = 0; i < n; i++) 
    {
        if (cash[i] > miss+1)
            break;
        miss += cash[i];
            
    }

    cout << miss+1;
}
