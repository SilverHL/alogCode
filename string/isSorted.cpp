#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string str[100];
    string cp[100];
    int len[100];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        cp[i] = str[i];
        len[i] = str[i].length();
    }
    
    bool lenFlag = true;
    bool dirFlag = false;

    sort(str, str+n);
    
    for (int i = 0; i < n; i++) {
        if (i < n-1 && len[i] > len[i+1]) 
            lenFlag = false;
        if (str[i] != cp[i]) 
            dirFlag = false;
    }

    if (dirFlag && lenFlag) 
        cout << "both" ;
    else if (!dirFlag && !lenFlag) 
        cout << "none" ;
    else if (dirFlag) 
        cout << "lexicographically";
    else
        cout << "lengths";

    return 0;

}
