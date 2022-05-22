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
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int ans{};
        int n = capacity.size();
        for (int i = 0; i < n; ++i)
        {
            capacity[i] -= rocks[i];
            ans += capacity[i] == 0;
        }
        vector<int> nn;
        copy_if(capacity.begin(), capacity.end(), inserter(nn, nn.begin()), [](const int &a)
                { return a != 0; });
        sort(nn.begin(), nn.end());
        int i = 0;
        while (i < nn.size() && additionalRocks >= nn[i])
        {
            additionalRocks -= nn[i];
            i++;
            ans++;
        }
        return ans;
    }
};

int main()
{
}