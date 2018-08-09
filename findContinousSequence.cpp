#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> >res;
    for (int i = sqrt(2 * sum); i >= 2; --i) {
        if ((i & 1) == 1 && sum % i == 0 || (sum % i) * 2 == i) {
            vector<int> tmp;
            for (int j = 0, k = (sum / i) - (i - 1) / 2; j < i; j++, k++) {
                tmp.push_back(k);
            }
            res.push_back(tmp);
        }
    }

    return res;
}
