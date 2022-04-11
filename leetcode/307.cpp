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

class NumArray
{

private:
    vector<int> tree;
    vector<int> &nums;
    int lowb(int x) { return x & (-x); }
    void add(int idx, int v)
    {
        while (idx < tree.size())
        {
            tree[idx] += v;
            idx += lowbidx);
        }
    }
    int prefix_sum(int idx)
    {
        int sum{};
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= lowb(idx);
        }
        return sum;
    }

public:
    NumArray(vector<int> &nums) : tree(nums.size() + 1), nums(nums)
    {
        for (int i{}; i < nums.size(); ++i)
        {
            add(i + 1, nums[i]);
        }
    }

    void update(int index, int val)
    {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right)
    {
        return prefix_sum(right + 1) - prefix_sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main()
{
}