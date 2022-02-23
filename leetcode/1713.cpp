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
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        int n = target.size();
        unordered_map<int, int> p;
        for (int i = 0; i < n; ++i)
        {
            p[target[i]] = i;
        }
        vector<int> d;
        for (int v : arr)
        {
            if (p.count(v))
            {
                int index = p[v];
                auto it = lower_bound(d.begin(), d.end(), index);
                if (it != d.end())
                {
                    *it = index;
                }
                else
                {
                    d.push_back(index);
                }
            }
        }
        return n - d.size();
    }
};
int main()
{
}