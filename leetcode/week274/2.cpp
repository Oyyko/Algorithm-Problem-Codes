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
    int numberOfBeams(vector<string> &bank)
    {
        int cnt{};
        vector<int> lines;
        for (auto &x : bank)
        {
            int cc{};
            for (auto &xx : x)
            {
                cc += xx == '1';
            }
            lines.push_back(cc);
        }
        for (int i{}; i < lines.size(); ++i)
        {
            for (int j{i + 1}; j < lines.size(); ++j)
            {
                if (lines[j] == 0)
                    continue;
                cnt += lines[i] * lines[j];
                break;
            }
        }
        return cnt;
    }
};

int main()
{
    vector<string> b = {"000", "111", "000"};
    Solution s;
    cout << s.numberOfBeams(b);
}