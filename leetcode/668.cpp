#include <bits/stdc++.h>

using namespace std;

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
    int findKthNumber(int m, int n, int k)
    {
        auto yes = [&m, &n, &k](int x)
        {
            int cnt{};
            for (int i = 1; i <= m; i++)
                cnt += min(x / i, n);
            return cnt >= k;
        };
        int l{1}, h{m * n};
        int mid{};
        while (l < h)
        {
            mid = l + (h - l) / 2;
            if (!yes(mid))
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};

int main()
{
}