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
    string minRemoveToMakeValid(string s)
    {
        int n = s.size();
        vector<bool> is_delete(n, false);
        int res;
        res = 0;
        for (int i{}; i < n; ++i)
        {
            if (s[i] == '(')
                res++;
            else if (s[i] == ')')
            {
                res--;
                if (res < 0)
                {
                    res = 0;
                    is_delete[i] = 1;
                }
            }
        }
        res = 0;
        for (int i{n - 1}; i >= 0; --i)
        {
            if (is_delete[i] == 1)
                continue;
            if (s[i] == ')')
                res++;
            else if (s[i] == '(')
            {
                res--;
                if (res < 0)
                    res = 0, is_delete[i] = 1;
            }
        }
        string ans;
        for (int i{}; i < n; ++i)
        {
            if (is_delete[i] == 1)
                continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main()
{
}