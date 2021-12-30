#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> int2nextbigger;
        vector<int> ans;
        stack<int> s;
        for (const auto &x : nums2)
        {
            if (s.empty() || s.top() > x)
            {
                s.push(x);
            }
            else
            {
                while (!s.empty() && s.top() < x)
                {
                    int2nextbigger[s.top()] = x;
                    s.pop();
                }
                s.push(x);
            }
        }
        if (!s.empty())
        {
            while (!s.empty())
            {
                int2nextbigger[s.top()] = -1;
                s.pop();
            }
        }
        for (auto &x : nums1)
        {
            ans.push_back(int2nextbigger[x]);
        }
        return ans;
    }
};

int main()
{
}