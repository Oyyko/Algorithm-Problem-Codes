#include <iostream>
#include <vector>

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
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        auto i = numbers.begin();
        auto j = numbers.end() - 1;
        vector<int> ans;
        while (1)
        {
            if (*i + *j == target)
            {
                ans.push_back(i - numbers.begin() + 1);
                ans.push_back(j - numbers.begin() + 1);
                return ans;
            }
            if (*i + *j < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    pr(s.twoSum(v, 9));
}