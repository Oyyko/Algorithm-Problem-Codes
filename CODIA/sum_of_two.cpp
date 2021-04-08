#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> m;
    vector<int> ans;
    auto itr = m.begin();
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i == 0)
        {
            m.insert(pair<int, int>(nums[i], i));
            continue;
        }
        itr = m.find(target - nums[i]);
        if (itr != m.end())
        {
            ans.push_back((*itr).second);
            ans.push_back(i);
        }
        m.insert(pair<int, int>(nums[i], i));
    }
    return ans;
}

int main()
{
    string first_line;
    getline(cin, first_line);
    int target;
    cin >> target;
    istringstream iss(first_line);
    // cout << target;
    char temp_char;
    int temp_int;
    vector<int> nums;
    while (iss >> temp_char >> temp_int)
    {
        if (temp_char == ']')
            break;
        nums.push_back(temp_int);
    }
    auto ans = twoSum(nums, target);
    cout << "[";
    cout << ans[0] << ", " << ans[1] << "]";
}