#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int tmp;
    vector<int> num;
    while (cin >> tmp) 
        num.push_back(tmp);

    int max = num[0];
    int res = num[0];
    for (int i = 1; i < num.size(); i++) 
    {
        if (res + num[i] > 0) 
        {
            res += num[i];
            if (res > max) 
                max = res;
        }
        else {
            res = 0;
        }
    }
    cout << max;

}
