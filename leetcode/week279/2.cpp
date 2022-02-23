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
    long long smallestNumber(long long num)
    {
        int digit[10] = {0};
        if (num > 0)
        {
            while (num)
            {
                digit[num % 10]++;
                num /= 10;
            }
            long long ans{};
            for (int i{1}; i <= 9; ++i)
            {
                if (digit[i])
                {
                    digit[i]--;
                    ans = i;
                    break;
                }
            }
            for (int i{}; i <= 9; ++i)
            {
                int k = digit[i];
                while (k)
                {
                    ans *= 10;
                    ans += i;
                    k--;
                }
            }
            return ans;
        }
        else if (num < 0)
        {
            num = -num;
            while (num)
            {
                digit[num % 10]++;
                num /= 10;
            }
            long long ans{};
            for (int i{9}; i >= 1; --i)
            {
                if (digit[i])
                {
                    digit[i]--;
                    ans = i;
                    break;
                }
            }
            for (int i{9}; i >= 0; --i)
            {
                int k = digit[i];
                while (k)
                {
                    ans *= 10;
                    ans += i;
                    k--;
                }
            }
            return -ans;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Solution s;
    cout << s.smallestNumber(-7605);
}