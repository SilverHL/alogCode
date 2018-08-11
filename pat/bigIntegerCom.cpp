#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        long a, b, c;
        cin >> a >> b >> c;

        if((a+b) > c) 
            cout << "Case #" << i << ": true" << endl;
        else 
            cout << "Case #" << i << ": false" << endl;
        i++;
    }

    
}
