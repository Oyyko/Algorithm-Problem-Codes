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
    int maxValue(int n, int index, int maxSum)
    {
        int diff = maxSum - n, left = index, right = index, res = 1, dl = 0, dr = 0;
        while (diff > 0)
        {
            if (--left >= 0)
                dl++;
            if (++right < n)
                dr++;
            if (left < 0 && right >= n)
            {
                res += diff % n == 0 ? diff / n : diff / n + 1;
                return res;
            }
            res += 1;
            diff -= (dl + dr + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.maxValue(4, 2, 6);
}