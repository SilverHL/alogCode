#include <iostream>

using namespace std;


int main()
{
    int m;
    int num[101];
    int total = 0;
    int avg;
    int count = 0;
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num[i];
        total += num[i];
    }
    if (total % m != 0) {
        cout << -1;
        return 0;
    }

    avg = total / m;

    for (int i = 0; i < m; i++) {
        if (abs(num[i] - avg) % 2 != 0) {
            cout << -1 ;
            return 0;
        }

        int tmp = abs(num[i] - avg);
        count += tmp / 2;
    }

    cout << count/2;
    return 0;


}
