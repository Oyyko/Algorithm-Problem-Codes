from typing import List

class Solution:
    def maxSubarrayLength(self, nums: List[int]) -> int:
        nums = [(nums[i],i) for i in range(len(nums))]
        nums.sort(reverse = True)
        print(nums);
        prevminidx = float('inf')
        cur = float('-inf')
        curminidx = float('inf')
        res = 0
        for num, i in nums:
            if cur != num:
                prevminidx = min(prevminidx, curminidx)
                cur = num
            curminidx = i
            print(i,curminidx,prevminidx)
            res = max(res, i - prevminidx + 1)
        return res
      
s= Solution();
print(s.maxSubarrayLength([4,7,3,2,8]))

