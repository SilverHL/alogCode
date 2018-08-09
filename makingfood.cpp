#include <bits/stdc++.h>

using namespace std;

int main()
{
    string temp;
    map<string, int> num;
    int count = 0;
    while (cin >> temp) {
        if (num[temp] == 0)
            count++;
    }
    
    cout << count;
}
