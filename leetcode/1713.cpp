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
        unordered_map<int, int> pos;
        for (int i{}, _ = target.size(); i < _; ++i)
            pos[target[i]] = i;
        vector<int> tmp;
        for (auto &x : arr)
        {
            if (pos.find(x) != pos.end())
            {
                tmp.push_back(pos[x]);
            }
        }
        vector<int> d;
        if (tmp.size() == 0)
            return target.size();
        d.push_back(tmp[0]);
        for (int i{1}, _ = tmp.size(); i < _; ++i)
        {
            int &x = tmp[i];
            if (x > d.back())
                d.push_back(x);
            else
            {
                auto l = lower_bound(d.begin(), d.end(), x);
                *l = x;
            }
        }
        return target.size() - d.size();
    }
};
int main()
{
}