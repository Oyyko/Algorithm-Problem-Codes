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
    int minAddToMakeValid(string s)
    {
        vector<int> v;
        for (auto &c : s)
        {
            if (c == '(')
                v.push_back(0);
            if (c == ')')
            {
                if (v.empty())
                {
                    v.push_back(1);
                    continue;
                }
                if (v.back() == 0)
                    v.pop_back();
                else
                    v.push_back(1);
            }
        }
        return v.size();
    }
};

int main()
{
}