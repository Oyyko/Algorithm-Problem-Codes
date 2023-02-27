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
    const int MOD = 1e9 + 7;
    using ll = long long;
    int squareFreeSubsets(vector<int> &nums)
    {
        ll ans{};
        unordered_map<int, int> mp;
        for (auto &i : nums)
        {
            mp[i]++;
        }
        unordered_map<int, int> a;
        a[1] = 1;
        a[2] = 0b00000000010;
        a[3] = 0b00000000100;
        a[5] = 0b00000001000;
        a[6] = 0b00000000110;
        a[7] = 0b00000010000;
        a[11] = 0b00000100000;
        a[13] = 0b00001000000;
        a[17] = 0b00010000000;
        a[19] = 0b00100000000;
        a[23] = 0b01000000000;
        a[29] - 0b10000000000;
        a[10] = a[2] + a[5];
        a[14] = a[2] + a[7];
        a[15] = a[3] + a[5];
        a[21] = a[3] + a[7];
        a[22] = a[11] + a[2];
        a[26] + a[13] + a[2];
        a[30] = a[2] + a[3] + a[5];
        unordered_map<int, int> b;
        // b[0b0000000000000000001] = 1;
        // b[0b0000000000000000010] = 2;
        // b[0b0000000000000000100] = 3;
        // b[0b0000000000000001000] = 5;
        // b[0b0000000000000010000] = 6;
        // b[0b0000000000000100000] = 7;
        // b[0b0000000000001000000] = 10;
        // b[0b0000000000010000000] = 11;
        // b[0b0000000000100000000] = 13;
        // b[0b0000000001000000000] = 14;
        // b[0b0000000010000000000] = 15;
        // b[0b0000000100000000000] = 17;
        // b[0b0000001000000000000] = 19;
        // b[0b0000010000000000000] = 21;
        // b[0b0000100000000000000] = 22;
        // b[0b0001000000000000000] = 23;
        // b[0b0010000000000000000] = 26;
        // b[0b0100000000000000000] = 29;
        // b[0b1000000000000000000] = 30;

        b[1] = 1;
        b[2] = 2;
        b[3] = 3;
        b[4] = 5;
        b[5] = 6;
        b[6] = 7;
        b[7] = 10;
        b[8] = 11;
        b[9] = 13;
        b[10] = 14;
        b[11] = 15;
        b[12] = 17;
        b[13] = 19;
        b[14] = 21;
        b[15] = 22;
        b[16] = 23;
        b[17] = 26;
        b[18] = 29;
        b[19] = 30;
        for (int i = 1; i < (1 << 19); ++i)
        {
            int now{};
            int ii = i;
            int cnt{};
            ll s{1};
            int cc{};
            while (ii)
            {
                int mod = ii % 2;
                ii /= 2;
                cnt++;
                if (mod == 1)
                {
                    if (now ^ a[b[cnt]] != now + a[b[cnt]])
                    {
                        goto NEXT;
                    }
                    else
                    {
                        s *= mp[b[cnt]];
                        if (s == 0)
                            goto NEXT;
                        s %= MOD;
                    }
                }
            }
            ans += s;
            ans %= MOD;
        NEXT:;
        }
        for (int i = 1; i <= 19; ++i)
        {
            ans -= mp[b[i]];
            if (mp[b[i]])
                ans += 1;
        }
        return ans;
    }
};

int main()
{
}