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
    int f(int a, int b, int c)
    {
        return a * 100 + b * 10 + c;
    }
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        set<int> ans;
        int n = digits.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    if (i == j || j == k || i == k)
                    {
                        continue;
                    }
                    if (digits[i] == 0)
                        continue;
                    if (digits[k] % 2 != 0)
                        continue;
                    ans.insert(f(digits[i], digits[j], digits[k]));
                }
            }
        }
        vector<int> aa;
        for (auto &x : ans)
        {
            aa.push_back(x);
        }
        return aa;
    }
};

int main()
{
    Solution s;
    vector<int> v{0, 0, 0};
    pr(s.findEvenNumbers(v));
}