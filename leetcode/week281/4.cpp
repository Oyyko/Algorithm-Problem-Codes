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
    inline int gcd(int a, int b)
    {
        return b > 0 ? gcd(b, a % b) : a;
    }

    long long coutPairs(vector<int> &nums, int k)
    {
        long long int ans = 0;
        const int M = 100000;
        vector<int> pl(M + 5, 0);
        int n = nums.size();
        int gg;
        int d2;
        for (int i = 0; i < n; i++)
        {
            gg = gcd(nums[i], k);
            ans += pl[k / gg];
            for (int j = 1; j <= static_cast<int>(sqrt(nums[i])); j++)
            {
                if (nums[i] % j == 0)
                {
                    d2 = nums[i] / j;
                    pl[j]++;
                    if (j != d2)
                    {
                        pl[d2]++;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 3, 4, 5};
    vector<int> v2{8, 10, 2, 5, 9, 6, 3, 8, 2};
    cout << s.coutPairs(v2, 6);
}