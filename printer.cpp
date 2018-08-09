#include <iostream>
#include <string>

using namespace std;

const int big = 100;

int main()
{
    int wig[27];
    for (int i = 0; i < 26; i++) 
        cin >> wig[i];

    string dst;
    cin >> dst;
    int line = 1;
    int total = 0;

    for (int i = 0; i < dst.length(); i++) 
    {
        int len = wig[dst[i]-'a'];
        total += len;
        if (total > 100) {
            total = len;
            line++;
        }
    }

    cout << line << " " << total;
}
