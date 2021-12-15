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
    int countPoints(string rings)
    {
        auto be_red = [](int n)
        { return n | 0b001; };
        auto be_green = [](int n)
        { return n | 0b010; };
        auto be_bule = [](int n)
        { return n | 0b100; };
        int state[102] = {0};
        auto f = [&](char c, int x)
        {
            if (c == 'B')
                return be_bule(x);
            else if (c == 'R')
                return be_red(x);
            else
                return be_green(x);
        };
        int m = rings.size();
        int n = m / 2;
        for (int i = 1; i <= n; ++i)
        {
            state[rings[2 * i - 1] - '0'] = f(rings[2 * i - 2], state[rings[2 * i - 1] - '0']);
        }
        int cnt = 0;
        for (int i = 0; i <= n; ++i)
        {
            cout << i << " " << state[i] << endl;
            if (state[i] == 0b111)
                cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    cout << s.countPoints("R1B1G1G2B2R2");
}