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
private:
    int cnt[1000005] = {0};

public:
    vector<int> findLonely(vector<int> &nums)
    {
        for (auto &x : nums)
        {
            cnt[x]++;
        }
        vector<int> v;
        for (auto &x : nums)
        {
            if (x != 0)
            {
                if (cnt[x] == 1 && cnt[x - 1] == 0 && cnt[x + 1] == 0)
                {
                    v.push_back(x);
                }
            }
            if (x == 0)
            {
                if (cnt[0] == 1 && cnt[1] == 0)
                {
                    v.push_back(0);
                }
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v{};
}