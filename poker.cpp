#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

    int num[10000000];
int main()
{
    int pir;
    int n, k;
    
    cin >> pir;
    while (pir--) {
        memset(num, 0, sizeof(num));
        cin >> n >> k;
        for (int i = 0; i< 2*n; i++) {
            int temp = i + 1;
            for (int j = 0; j < k; j++) 
                if (temp > n) 
                    temp = 2 * (temp - n);
                else 
                    temp = 2 * temp - 1;
            cin >> num[temp-1];
        }
         
        for (int i = 0; i < 2*n; i++) {
            if (pir == 0 && i == 2*n - 1)
                cout << num[i];
            else 
                cout << num[i] << " ";
        }
    }
    return 0;
}
