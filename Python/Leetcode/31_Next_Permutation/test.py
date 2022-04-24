# Solution from leetcode animation
from typing import List
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        pre = len(nums) - 1
        if (pre <= 0): 
            return
        up = pre - 1
        while(nums[up] >= nums[pre] and up >= -1):
            up -= 1
            pre -= 1
        if (up == -1):
            nums[:] = nums[::-1]
            return
        
        new_up = up + 1
        while(new_up < len(nums) - 1 and nums[new_up + 1] > nums[up]):
            new_up += 1
        tmp = nums[up]
        nums[up] = nums[new_up]
        nums[new_up] = tmp

        nums[up + 1:] = nums[up + 1:][::-1]
        
