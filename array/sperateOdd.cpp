#include <bits/stdc++.h>

using namespace std;

void 
reOrderArray(vector<int> &array) 
{
    int i;
    for (int i = 1; i < array.size(); i++) {
        if (array[i] % 2 == 0) {
            for (int j = i; j < array.size(); j++) {
                if (array[j] % 2 == 1) {
                    int temp = array[j];
                    while (j > i) {
                        array[j] = array[j-1];
                        j--;
                    }

                    array[j] = temp;
                    i++;
                }
            }
        }       
    }
}
