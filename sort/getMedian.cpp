#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    priority_queue<int, vector<int>, less<int> >p;
    priority_queue<int, vector<int>, greater<int> >q;

    void Insert(int num) {
        if (p.empty() || num > p.top()) {
            p.push(num);
        } else 
            q.push(num);

        if (p.size() + 2 == q.size()) {
            p.push(q.top());
            q.pop();
        } else if (q.size() + 1 == p.size()) {
            q.push(q.top());
            q.pop();
        }
    }

    double GetMedian() {
        return (p.size() == q.size() ? (p.top() + q.top()) / 2.0 : q.top());
    }
};
