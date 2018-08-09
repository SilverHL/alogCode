#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main()
{
    string str;
    string res;
    int num = 1;
    cin >> str;
    int j;
    for (int i = 0; i < str.length(); i++)
    {
        num = 0;
        for (j = i; str[i] == str[j] && j < str.length(); j++) 
        {
            if (str[i] == str[j]) 
                num++;
            else 
                break;
        }
        res += to_string(num) + str[i];
        i = j-1;
    }

    cout << res;
}
