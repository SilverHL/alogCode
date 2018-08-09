#include <iostream>

using namespace std;

int main()
{
    int num;
    int length;
    string s;
    int count = 0;

    cin >> num;
    while (num--) {
        cin >> length;
        cin >> s;
        count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') {
                count++;
                i += 2;
            }
        }
        cout << count;
    }
}
