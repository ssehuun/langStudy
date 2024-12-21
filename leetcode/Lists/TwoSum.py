
class Solution:

    # HashMap2 Solution
    def twoSum(self, nums: List[int], target: int) -> List[int]:
                hashmap = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap:
                return [i, hashmap[complement]]
            hashmap[nums[i]] = i
        # Return an empty list if no solution is found
        return []


    # HashMap Solution1
    hashmap = {}
    for i in range(len(nums)):
        hashmap[nums[i]] = i
    for i in range(len(nums)):
        comp = target - nums[i]
        if comp in hashmap and hashmap[comp] != i :
            return [i, hashmap[comp]]


    # Brute Force Solution
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        output = list()
        for i in range(len(nums)):
            tmp_sum = nums[i]
            # print(f"tmp_sum 1: {tmp_sum}")
            for j in range(i + 1, len(nums)):
                tmp_sum += nums[j]
                # print(f"tmp_sum 2: {tmp_sum}")
                if tmp_sum == target:
                    output.append(i)
                    output.append(j)
                    return output
                else:
                    tmp_sum = nums[i]

