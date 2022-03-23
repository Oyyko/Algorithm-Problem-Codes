#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
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
    bool winnerOfGame(string colors)
    {
        int cnt1{}, cnt2{};
        int cnt{};
        char last_char{'0'};
        for (auto &c : colors)
        {
            if (last_char == '0')
            {
                cnt++;
                last_char = c;
            }
            else if (last_char == 'A')
            {
                if (c == 'A')
                {
                    cnt++;
                }
                else
                {
                    cnt1 += (cnt - 2) >= 0 ? cnt - 2 : 0;
                    cnt = 1;
                    last_char = 'B';
                }
            }
            else
            {
                if (c == 'A')
                {
                    cnt2 += (cnt - 2) >= 0 ? cnt - 2 : 0;
                    cnt = 1;
                    last_char = 'A';
                }
                else
                {
                    cnt++;
                }
            }
        }
        if (last_char == 'A')
        {

            cnt1 += (cnt - 2) >= 0 ? cnt - 2 : 0;
        }

        else
        {
            cnt2 += (cnt - 2) >= 0 ? cnt - 2 : 0;
        }

        // cout << cnt1 << endl
        //      << cnt2;
        return cnt1 > cnt2;
    }
};

int main()
{
    Solution s;
    s.winnerOfGame("AAAABBBB");
}