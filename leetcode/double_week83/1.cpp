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
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        auto ss = suits.front();
        bool all_same = 1;
        for (auto &x : suits)
        {
            if (x != ss)
            {
                all_same = 0;
                break;
            }
        }
        if (all_same)
        {
            return string("Flush");
        }
        auto res2 = "Three of a Kind"s;
        auto res3 = "Pair"s;
        auto res4 = "High Card"s;
        int same_one = 0;
        int tmp = 1;
        for (int i = 0; i < 5; ++i)
        {
            tmp = 1;
            for (int j = i + 1; j < 5; ++j)
            {
                if (ranks[i] == ranks[j])
                {
                    tmp++;
                }
            }
            same_one = max(same_one, tmp);
        }
        if (same_one >= 3)
            return res2;
        if (same_one == 2)
            return res3;
        return res4;
    }
};

int main()
{
}