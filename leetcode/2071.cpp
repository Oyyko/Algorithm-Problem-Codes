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
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        size_t n{tasks.size()};
        size_t m{workers.size()};
        size_t l{0}, r{min(n, m)};
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater());
        // partial_sort(workers.begin(), workers.begin() + r, workers.end(), greater());
        auto yes = [&](int mid) -> bool
        {
            int p{pills};
            multiset<int> ms(begin(workers), begin(workers) + mid);
            for (int i = mid - 1; i >= 0; --i)
            {
                auto t = tasks[i];
                if (auto itr{prev(ms.end())}; *itr >= t)
                    ms.erase(itr);
                else
                {
                    if (!p)
                        return false;
                    auto r{ms.lower_bound(t - strength)};
                    if (r == ms.end())
                        return false;
                    --p;
                    ms.erase(r);
                }
            }
            return true;
        };
        int mid;
        while (l < r)
        {
            mid = (l + r + 1) / 2;
            if (yes(mid))
                l = mid;
            else
                r = mid - 1;
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> t{74, 41, 64, 20, 28, 52, 30, 4, 4, 63};
    vector<int> v{38};
    cout << s.maxTaskAssign(t, v, 0, 68);
}