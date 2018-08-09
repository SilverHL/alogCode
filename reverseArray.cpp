#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> deq;
    int temp;
    int n;
    int res = 0;

    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> temp;
        deq.push_back(temp);
    }
    
    while (!deq.empty()) 
    {
        if(deq.front() == deq.back()) 
        {
            deq.pop_front();
            deq.pop_back();
        } else if (deq.front() < deq.back())  
        {
           int t = deq.front();
           deq.pop_front();
           t += deq.front();
           deq.pop_front();
           deq.push_front(t);
           res++;
        } else 
        {
            int t = deq.back();
            deq.pop_back();
            t += deq.back();
            deq.pop_back();
            deq.push_back(t);
            res++;
        }
    }

    cout << res;
    return 0;
}
