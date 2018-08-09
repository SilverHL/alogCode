#include <iostream>

using namespace std;

bool isBack(string s1)
{
    int i = 0; 
    int j = s1.length()-1;

    while (i < j) {
        if (s1[i] != s1[j]) 
            return false;
        i++;
        j--;
    }

    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    string temp = s1;
    int count = 0;

    for (int i = 0; i <= s1.length(); i++) {
        temp = s1;
        temp.insert(i, s2);
        if (isBack(temp)) 
            count += 1;
    }

    cout << count;
    return 0;
}
