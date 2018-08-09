#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int queue[1000];
    int ans[1000];

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> queue[i];

    sort(queue, queue+n);

    int low = 0;
    int high = n-1;
    
    int flag = 1;
    
    int pos = (n-1) / 2;
    int left = pos;
    int right = pos+1;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (flag) {
            ans[left--] = queue[high--];
        } else {
            ans[right++] = queue[low++];
        }

        flag = flag == 1 ? 0 : 1;
    }

    int tmp;

    for (int i = 0; i < n-1; i++) {
        tmp = ans[i] - ans[i+1];
        cout << tmp << endl;;
        if (tmp > 0) 
            sum += tmp;
        else 
            sum -= tmp;
    }

    cout << sum;

}
