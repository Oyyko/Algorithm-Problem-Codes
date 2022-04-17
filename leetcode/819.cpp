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
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        for (auto &x : paragraph)
        {
            x = tolower(x);
            if (x == ',' || x == '.' || x == '?' || x == ';' || x == '!' || x == '\'')
            {
                x = ' ';
            }
        }
        unordered_set<string> ban;
        for (auto &s : banned)
            ban.insert(s);
        stringstream ss{paragraph};
        string tmp;
        unordered_map<string, int> cnt;
        while (ss >> tmp)
        {
            if (ban.find(tmp) == ban.end())
            {
                cnt[tmp]++;
            }
        }
        auto itr_max = cnt.begin();
        for (auto itr = cnt.begin(); itr != cnt.end(); ++itr)
        {
            if (itr->second > itr_max->second)
            {
                itr_max = itr;
            }
        }
        return itr_max->first;
    }
};

int main()
{
}