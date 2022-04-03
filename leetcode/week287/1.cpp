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
    int convertTime(string current, string correct)
    {
        if (current == correct)
            return 0;
        auto trans = [](string &str)
        {
            int h{};
            h = str[0] - '0';
            h *= 10;
            h += str[1] - '0';
            int min{};
            min = str[3] - '0';
            min *= 10;
            min += str[4] - '0';
            return h * 60 + min;
        };
        int c1 = trans(current);
        int c2 = trans(correct);
        int diff = c2 - c1;
        int ans{};
        while (diff >= 60)
        {
            diff -= 60, ans++;
        }
        while (diff >= 15)
        {
            diff -= 15, ans++;
        }
        while (diff >= 5)
        {
            diff -= 5;
            ans++;
        }
        while (diff >= 1)
        {
            diff -= 1;
            ans++;
        }
        return ans;
    }
};

int main()
{
}