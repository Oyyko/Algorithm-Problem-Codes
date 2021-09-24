#include <iostream>
#include <vector>

// 错误点：-2147483648的特殊性
// 原解法：全转换为正数，但实际上int能容纳的负数范围更大
// 现解发：全转换为负数

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (!dividend)
        {
            return 0;
        }
        if (divisor == INT32_MIN)
        {
            return dividend == INT32_MIN ? 1 : 0;
        }
        if (dividend == INT32_MIN && divisor == -1)
        {
            return INT32_MAX;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        if (dividend < 0 && divisor < 0)
        {
            int ans{};
            int now_weight{divisor};
            int now_weight_digit{};
            while (now_weight >= dividend / 2)
            {
                now_weight *= 2;
                now_weight_digit++;
            }
            while (dividend <= divisor)
            {
                if (dividend <= now_weight)
                {
                    dividend -= now_weight;
                    ans += (1 << now_weight_digit);
                }
                now_weight /= 2;
                now_weight_digit--;
            }
            return ans;
        }
        else
        {
            if (dividend > 0 && divisor > 0)
            {
                return divide(-abs(dividend), -abs(divisor));
            }
            else
            {
                return -divide(-abs(dividend), -abs(divisor));
            }
        }
    }
};

int main()
{
    Solution s;
    cout << s.divide(100, 2);
}