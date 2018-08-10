#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *favor = new int[n+1]();
    unordered_multimap<int, int> fmap;

    for (int i = 1; i <= n; i++) 
    {
        cin >> favor[i];
        fmap.insert(make_pair(favor[i], i));
    }

    int q;
    cin >> q;
    vector<int> ans;
    while (q--) 
    {
        int l, r, k, cnt = 0;
        cin >> l >> r >> k;
        auto range = fmap.equal_range(k);
        for (auto i = range.first; i != range.second; i++) 
            if (i->second >= l && i->second <= r) 
                ++cnt;
        ans.push_back(cnt);
    }

    for (auto i : ans) 
        cout << i << endl;
    return 0;
}

