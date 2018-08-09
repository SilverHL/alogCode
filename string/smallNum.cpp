#include <bits/stdc++.h>

using namespace std;

static bool cmp(int a, int b)
{
    string A = "";
    string B = "";

    A += to_string(a);
    A += to_string(b);
    B += to_string(b);
    B += to_string(a);

    return A < B;
}

string PrintMinNumber(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), cmp);        

    string res = "";
    for (int i = 0; i < numbers.size(); i++) 
        res += to_string(numbers[i]);

    return res;
}
