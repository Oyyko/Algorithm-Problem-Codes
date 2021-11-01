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
private:
    typedef long long LL;

public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        auto is = [&nums1, &nums2, k](LL m)
        {
            LL cnt{};
            for (auto &x : nums1)
            {
                if (x > 0)
                {
                    cnt += upper_bound(nums2.begin(), nums2.end(), floor(m / x)) - nums2.begin();
                }
                if (x == 0 && m >= 0)
                {
                    cnt += nums2.size();
                }
                if (x < 0)
                {
                    cnt += nums2.size() - (lower_bound(nums2.begin(), nums2.end(), ceil(m / x)) - nums2.begin());
                    cout << "   DIFF: " << nums2.size() - (lower_bound(nums2.begin(), nums2.end(), ceil(m / x)) - nums2.begin()) << endl;
                    cout << "   ---MID: " << m << "X: " << x << endl;
                }
            }
            cout << "MID: " << m << " CNT: " << cnt << endl
                 << endl;
            return cnt >= k;
        };
        auto maxx1 = max(abs(nums1.back()), abs(nums1.front()));
        auto maxx2 = max(abs(nums2.back()), abs(nums2.front()));
        auto bound = maxx1 * (0ll + maxx2);
        LL l{-bound}, r{bound};
        LL mid;
        while (l < r)
        {
            cout << "L:" << l << "R:" << r << endl;
            mid = l + (r - l) / 2;
            if (is(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    Solution x;
    vector<int> v1{-2, -1, 0, 1, 2};
    vector<int> v2{-3, -1, 2, 4, 5};
    pr(v1);
    pr(v2);
    cout << endl;
    vector<int> s;
    for (auto x : v1)
    {
        for (auto y : v2)
        {
            s.push_back(x * y);
        }
    }
    sort(s.begin(), s.end());
    pr(s);
    cout << "SIZE:" << s.size() << endl;
    cout << x.kthSmallestProduct(v1, v2, 3);
}