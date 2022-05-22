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
    int repeatedNTimes(vector<int> &nums)
    {
        int n = nums.size();
        mt19937 gen(random_device{}());
        uniform_int_distribution<int> r(0, n - 1);
        while (1)
        {
            int x = r(gen), y = r(gen);
            if (x != y && nums[x] == nums[y])
                return nums[x];
        }
    }
};

int main()
{
}