#include <bits/stdc++.h>

using namespace std;

using LL = long long;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a << " ";
    }
    cout << endl;
}

class Solution
{
public:
    using ll = long long;
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        if (k == 1 || n == k)
            return 0;
        vector<ll> v(n - 1, 0ll);
        for (int i = 0; i < n - 1; ++i)
        {
            v[i] = weights[i] + weights[i + 1];
        }
        sort(v.begin(), v.end());
        ll maxx{}, minn{};
        for (int i = 0; i < k - 1; ++i)
        {
            maxx += v[i];
            minn += v[n - 2 - i];
        }
        // pr(v);
        // cout << maxx << " " << minn << endl;
        return -maxx + minn;
    }
};

int main()
{
    vector<int> v{1, 3, 5, 1};
    vector<int> v2{1, 3};
    vector<int> v3{1, 4, 2, 5, 2};
    Solution s;
    cout << s.putMarbles(v, 2) << endl;
    cout << s.putMarbles(v2, 2) << endl;
    cout << s.putMarbles(v3, 3) << endl;
}