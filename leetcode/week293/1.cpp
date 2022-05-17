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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    bool yes(string x, string y)
    {
        if (x.size() != y.size())
            return 0;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return x == y;
    }
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;
        stack<int> ss;
        int n = words.size();
        for (int i = n - 1; i >= 0;)
        {
            int j;
            for (j = i; j >= 0; --j)
            {
                if (yes(words[i], words[j]))
                {
                }
                else
                    break;
            }
            ss.push(j + 1);
            i = j;
        }
        while (!ss.empty())
        {
            ans.push_back(words[ss.top()]);
            ss.pop();
        }
        return ans;
    }
};

int main()
{
}