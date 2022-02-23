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
    int findFinalValue(vector<int> &nums, int original)
    {
        set<int> s;
        for (auto &x : nums)
        {
            s.insert(x);
        }
        while (s.find(original) != s.end())
        {
            original *= 2;
        }
        return original;
    }
};

int main()
{
    Solution s;
    
}