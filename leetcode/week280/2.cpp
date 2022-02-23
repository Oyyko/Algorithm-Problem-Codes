#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
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
    int minimumOperations(vector<int> &nums)
    {
        map<int, int> odd;
        map<int, int> even;
        int n = nums.size();
        for (int i{}; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                even[nums[i]]++;
            }
            else
            {
                odd[nums[i]]++;
            }
        }
        int odd_max{};
        int odd_max_cnt{};
        int odd_second_max{};
        int odd_second_max_cnt{};
        for (auto &[num, cnt] : odd)
        {
            if (cnt > odd_max_cnt)
            {
                odd_second_max = odd_max;
                odd_second_max_cnt = odd_max_cnt;
                odd_max = num;
                odd_max_cnt = cnt;
            }
            else if (cnt > odd_second_max_cnt)
            {
                odd_second_max = num;
                odd_second_max_cnt = cnt;
            }
        }
        int even_max{};
        int even_max_cnt{};
        int even_second_max{};
        int even_second_max_cnt{};
        for (auto &[num, cnt] : even)
        {
            // cout << num << " " << cnt << endl;
            if (cnt > even_max_cnt)
            {
                even_second_max = even_max;
                even_second_max_cnt = even_max_cnt;
                even_max = num;
                even_max_cnt = cnt;
            }
            else if (cnt > even_second_max_cnt)
            {
                even_second_max = num;
                even_second_max_cnt = cnt;
            }
        }
        if (even_max != odd_max)
            return n - odd_max_cnt - even_max_cnt;
        return min(n - odd_max_cnt - even_second_max_cnt, n - even_max_cnt - odd_second_max_cnt);
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 2, 2, 2};
    vector<int> v2{3, 1, 3, 2, 4, 3};
    vector<int> v3{1, 2, 1, 2, 1, 2, 1, 3, 1, 3, 1, 3};
    cout << s.minimumOperations(v3);
}