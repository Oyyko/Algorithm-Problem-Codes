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
    int num[200005] = {0};
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int ans{};
        int now{};
        for (auto &x : fruits)
        {
            num[x[0]] = x[1];
        }
        int right;
        for (right = startPos; (right <= startPos + k) && (right <= 200000); ++right)
        {
            now += num[right];
        }
        ans = max(ans, now);
        right--;

        for (int i = 1; (2 * i <= right - startPos) && (startPos - i >= 0); ++i)
        {
            now += num[startPos - i];
            now -= num[right - 2 * i + 1];
            now -= num[right - 2 * i + 2];
            ans = max(ans, now);
        }
        now = 0;
        int left;
        for (left = startPos; (left >= startPos - k) && (left >= 0); --left)
        {
            now += num[left];
        }
        left++;
        ans = max(ans, now);
        for (int i = 1; (2 * i <= startPos - left) && (startPos + i <= 200000); ++i)
        {
            now += num[startPos + i];
            now -= num[left + 2 * i - 1];
            now -= num[left + 2 * i - 2];
            ans = max(ans, now);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
    cout << "ANS:" << s.maxTotalFruits(v, 5, 4);
}