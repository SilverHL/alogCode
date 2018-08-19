/***
 * A string s is LUCKY if and only if the number of different characters in s is a fibonacci 
 * number. Given a string consisting of only lower case letters , output all its lucky non-empty 
 * substrings in lexicographical order. Same substrings should be printed once.
 * **/

#include <bits/stdc++.h>

using namespace std;

int fibo[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

int main()
{
    string str;
    cin >> str;
    set<string> out;

    for (int i = 0; i < str.size(); i++)
    {
        set<char> m;
        int f = 1;
        for (int j = i; j < str.size(); j++)
        {
            m.insert(str[j]);
            if (m.size() == fibo[f])
                out.insert(str.substr(i, j - i + 1));
            else if (m.size() == fibo[f+1])
                j--, f++; 
        }
    }

    for (auto i = out.begin(); i != out.end(); i++)
        cout << *i << endl;
}

