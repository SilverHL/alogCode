#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

void combination(vector<int> vec, LL bag, int &ans)
{
   if (vec.empty()) 
       return;
   int n = vec.size();
   int nBit = 1 << n;
   for (int i = 1; i < nBit; i++) {
       LL tmp = bag;
       for (int j = 0; j <= (log2(i)+1); i++) {

       }
   } 
}

int main()
{
    int num, weight;
    vector<int> v;


}
