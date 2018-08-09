#include <bits/stdc++.h>

using namespace std;

#define MAX 2*100000

int a[MAX];
int b[MAX];

int main()
{
    long long int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left, right;
    if (n == 2) {
        cout << a[1] << " " << a[0];
        return 0;
    }

    int flag = n % 2;
    if (flag == 0) {
        right = n / 2;
        left = right-1;
    } else {
        right = (n+1) / 2;
        left = n / 2;
    }
    for (int i = 0; i < n; i++) {
        if (flag == 0) {
            if (i % 2 == 0) 
                b[right++] = a[i];
            else 
                b[left--] = a[i];
        } else {
            if (i % 2 == 0) 
                b[left--] = a[i];
            else 
                b[right++] = a[i];
            if (i == n-1) 
                b[0] = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i];
        if (i < n-1) 
            cout << " ";
    }
}
