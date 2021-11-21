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
    int maxDistance(vector<int> &colors)
    {
        int n = colors.size();
        int ans{-1};
        for (int i = 0; i < n; ++i)
        {
            int now_color = colors[i];
            for (int j = n - 1; j > i; --j)
            {
                if (colors[j] != now_color)
                {
                    ans = max(ans, j - i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{0, 1};
    cout << s.maxDistance(v);
}