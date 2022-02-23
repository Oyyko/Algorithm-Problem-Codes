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
    int minimumTime(string s)
    {
        int ans{};
        {
            int last_ll{};
            while (1)
            {
                // cout << "LL" << last_ll << endl;
                bool z = 1;
                int zz = 0;
                int ll = last_ll;
                // cout << "ll" << last_ll << endl;
                if (last_ll == s.size())
                    break;
                for (; ll < s.size(); ++ll)
                {
                    // cout << ll << " " << zz << " " << z << endl;
                    if (z)
                    {
                        if (s[ll] == '0')
                            zz++;
                        else
                            z = 0, ll--;
                    }
                    else
                    {
                        if (s[ll] == '1')
                        {
                            zz--;
                        }
                        else
                            break;
                    }
                }
                // cout << "ZZ" << zz << endl;
                if (zz <= 0)
                {
                    ans += ll - last_ll;
                    last_ll = ll;
                }
                else
                    break;
            }

            // cout << "RRR" << last_ll << endl;
            int r = s.size() - 1;
            int last_rr{r};
            while (1)
            {
                if (last_ll == s.size())
                    break;
                bool z = 1;
                int zz = 0;
                int rr = last_rr;
                if (last_rr == last_ll)
                    break;
                for (; rr >= last_ll; --rr)
                {
                    if (z)
                    {
                        if (s[rr] == '0')
                            zz++;
                        else
                            z = 0, rr++;
                    }
                    else
                    {
                        if (s[rr] == '1')
                        {
                            zz--;
                        }
                        else
                            break;
                    }
                }
                if (zz <= 0)
                {
                    ans += last_rr - rr;
                    last_rr = rr;
                }
                else
                    break;
            }
            // cout << "LL" << last_ll << "RR" << last_rr << endl;
            for (int k = last_ll; k <= last_rr; ++k)
            {
                if (s[k] == '1')
                    ans += 2;
            }
        }
        // cout << "111" << endl;
        int ans2{ans};
        ans = 0;
        {
            int r = s.size() - 1;
            int last_rr{r};
            while (1)
            {
                bool z = 1;
                int zz = 0;
                int rr = last_rr;
                // cout << "RR" << last_rr << endl;
                if (last_rr == -1)
                    break;
                for (; rr >= 0; --rr)
                {
                    if (z)
                    {
                        if (s[rr] == '0')
                            zz++;
                        else
                            z = 0, rr++;
                    }
                    else
                    {
                        if (s[rr] == '1')
                        {
                            zz--;
                        }
                        else
                            break;
                    }
                }
                if (zz <= 0)
                {
                    ans += last_rr - rr;
                    last_rr = rr;
                }
                else
                    break;
            }
            // cout << "222" << endl;
            int last_ll{};
            while (1)
            {
                if (last_rr == -1)
                    break;
                // cout << "LL" << last_ll << endl;
                bool z = 1;
                int zz = 0;
                int ll = last_ll;
                if (last_ll == last_rr)
                    break;
                for (; ll < last_rr; ++ll)
                {
                    // cout << ll << " " << zz << " " << z << endl;
                    if (z)
                    {
                        if (s[ll] == '0')
                            zz++;
                        else
                            z = 0, ll--;
                    }
                    else
                    {
                        if (s[ll] == '1')
                        {
                            zz--;
                        }
                        else
                            break;
                    }
                }
                // cout << "ZZ" << zz << endl;
                if (zz <= 0)
                {
                    ans += ll - last_ll;
                    last_ll = ll;
                }
                else
                    break;
            }

            for (int k = last_ll; k <= last_rr; ++k)
            {
                if (s[k] == '1')
                    ans += 2;
            }
        }
        // cout << "ANS2" << ans2 << " ANS" << ans << endl;
        return min(ans, ans2);
    }
};

int main()
{
    Solution s;
    cout << s.minimumTime("0010");
}