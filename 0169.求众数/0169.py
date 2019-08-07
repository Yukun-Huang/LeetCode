# 排序
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return nums[0]
        nums = sorted(nums)
        return nums[len(nums)//2]

# 哈希
class Solution_hash:
    def majorityElement(self, nums: List[int]) -> int:
        n, D = len(nums), {}
        for num in nums:
            if num in D:
                D[num] += 1
            else:
                D[num] = 1
            if D[num] > n/2:
                return num
