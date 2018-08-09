#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    deque<int> deq;

    cin >> n;
    for (int i = n; i > 0; --i) 
    {
        deq.push_front(i);
        int t = deq.back();
        deq.pop_back();
        deq.push_front(t);

    }

    for (int i = 0; i < deq.size(); i++) 
        if (i != deq.size()-1)
            cout << deq[i] << " ";
        else 
            cout << deq[i];

    return 0;
}
