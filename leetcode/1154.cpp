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
    int dayOfYear(string date)
    {
        int ans{};
        ans += date[8] - '0';
        ans *= 10;
        ans += date[9] - '0';
        int m = date[5] - '0';
        m *= 10;
        m += date[6] - '0';
        int y{};
        y += date[0] - '0';
        y *= 10;
        y += date[1] - '0';
        y *= 10;
        y += date[2] - '0';
        y *= 10;
        y += date[3] - '0';
        bool run{false};
        if (y % 100 != 0)
        {
            run = y % 4 == 0;
        }
        else
        {
            run = y % 400 == 0;
        }
        for (int i = 1; i <= m - 1; ++i)
        {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
            {
                ans += 31;
                continue;
            }
            if (i == 2)
            {
                ans += run ? 29 : 28;
                continue;
            }
            ans += 30;
        }
        return ans;
    }
};

int main()
{
}