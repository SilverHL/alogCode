#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string t;

    cin >> s ;
    cin >> t;

    int i = 0, j = 0;
    bool isSub = false;

    while (i < s.length() && j < t.length()) 
    {
        if (s[i] != t[j]) 
        {
            i++;
            continue;
        }

        if (s[i] == t[j])
        {
            i++;
            j++;
        }
    }

    if (j == t.length()) 
        cout << "Yes";
    else 
        cout << "No";

    return 0;
}
