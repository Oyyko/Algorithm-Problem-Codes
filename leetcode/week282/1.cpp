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
    int prefixCount(vector<string> &words, string pref)
    {
        int cnt{};
        int l = pref.size();
        for (auto &x : words)
        {
            cnt += (x.substr(0, l) == pref);
        }
        return cnt;
    }
};

int main()
{
}