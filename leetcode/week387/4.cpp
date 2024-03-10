#include "../base.hpp"
#include <vector>

class Solution {
public:
  std::vector<int> resultArray(std::vector<int> &nums) {
    std::multiset<int> arr1, arr2;
    std::vector<int> v1, v2;
    std::vector<int> result;

    arr1.insert(nums[0]);
    v1.emplace_back(nums[0]);
    v2.emplace_back(nums[1]);
    arr2.insert(nums[1]);
    int skip{};
    for (int num : nums) {
      if (skip < 2) {
        skip++;
        continue;
      }
      // 计算arr1和arr2中大于num的元素数量
      int greaterCount1 = distance(arr1.upper_bound(num), arr1.end());

      int greaterCount2 = distance(arr2.upper_bound(num), arr2.end());

      // 根据题目条件分配元素到arr1或arr2
      if (greaterCount1 > greaterCount2) {
        arr1.insert(num);
        v1.push_back(num);
      } else if (greaterCount1 < greaterCount2) {
        arr2.insert(num);
        v2.push_back(num);
      } else { // 如果数量相同，比较大小并分配
        if (arr2.size() < arr1.size()) {
          arr2.insert(num);
          v2.push_back(num);
        } else {
          arr1.insert(num);
          v1.push_back(num);
        }
      }
    }

    // 合并arr1和arr2到result
    result.insert(result.end(), v1.begin(), v1.end());
    result.insert(result.end(), v2.begin(), v2.end());

    return result;
  }
};

int main() {}