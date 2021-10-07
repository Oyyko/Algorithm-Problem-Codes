#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> v;
    int x = -1;
    while (x != 0)
    {
        cin >> x;
        v.push_back(x);
    }
    Solution s;
    pr(s.twoSum(v, 10));
}