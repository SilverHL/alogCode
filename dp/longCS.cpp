#include <bits/stdc++.h>

using namespace std;

#define LEFTUP 0
#define LEFT 1
#define UP 2

int max(int a, int b, int c, int *max_)
{
    int res = 0;
    *max_ = a;
    if (b > *max_) {
        *max_ = b;
        res = 1;
    }

    if (c > *max_) {
        *max_ = c;
        res = 2;
    }
    return res;
}

string LCS(const string &str1, const string &str2)
{
    int xlen = str1.length();
    int ylen = str2.length();

    if (xlen == 0 || ylen == 0) 
        return "";
    pair<int, int> arr[ylen][xlen+1];
    for (int i = 0; i <= xlen; i++) 
        arr[0][i].first = 0;
    for (int j = 0; j <= ylen; j++) 
        arr[j][0].first = 0;
    for (int i = 1;l)
}

int main()
{
    string str1 = "GCCCTACG";
    string str2 = "GCGCAATG";
    string lcs = LCS(str1, str2);
    cout << lcs << endl;
    return 0;
}
