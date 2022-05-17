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
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); ++i)
        {
            mp[order[i]] = i;
        }
        return is_sorted(words.begin(), words.end(), [&](const string &x, const string &y) -> bool
                         { 
                            int i = 0, j = 0, n1 = x.size(), n2 = y.size(); 
                            while(i<n1&&j<n2)
                            {
                                if(mp[x[i]]!=mp[y[i]])
                                return mp[x[i]]<mp[y[i]];
                                i++,j++;
                            }
                            return n1<n2; });
    }
};
int main()
{
}