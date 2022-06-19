#include <iostream>
#include <random>
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
    string greatestLetter(string s)
    {
        int yes[1000] = {0};
        for (auto &c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                if (yes[c - 'a' + 'A'] == 0)
                {
                    yes[c - 'a' + 'A'] = 1;
                }
                if (yes[c - 'a' + 'A'] == 2)
                {
                    yes[c - 'a' + 'A'] = 3;
                }
            }
            else
            {
                if (yes[c] == 0)
                {
                    yes[c] = 2;
                }
                if (yes[c] == 1)
                {
                    yes[c] = 3;
                }
            }
        }
        for (char x = 'Z'; x >= 'A'; --x)
        {
            if (yes[x] == 3)
            {
                string ans;
                ans.push_back(x);
                return ans;
            }
        }
        return string{};
    }
};

int main()
{
}