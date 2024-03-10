from bisect import bisect_right


class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        v1 = [nums[0]]
        v2 = [nums[1]]
        skip = 0
        for num in nums:
            if skip < 2:
                skip += 1
                continue
            # Find the number of elements greater than num in arr1 and arr2 using binary search
            count1 = len(arr1) - bisect_right(arr1, num)
            count2 = len(arr2) - bisect_right(arr2, num)
            

            # Decide which array to insert num into
            if count1 > count2:
                # Insert using binary search to keep arr2 sorted
                arr1.insert(bisect_right(arr1, num), num)
                v1.append(num)
            elif count1 < count2:
                # Insert using binary search to keep arr1 sorted
                arr2.insert(bisect_right(arr2, num), num)
                v2.append(num)
            else:
                # If there is a tie, insert into the shorter array, defaulting to arr1
                if len(arr2) < len(arr1):
                    arr2.insert(bisect_right(arr2, num), num)
                    v2.append(num)
                else:
                    arr1.insert(bisect_right(arr1, num), num)
                    v1.append(num)

        # Concatenate arr1 and arr2 to form the result
        return v1+v2
