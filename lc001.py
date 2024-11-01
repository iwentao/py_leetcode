# Wentao Sun 2024-11-1
# in Py3
# NOTICE:
# 1. use dict, not set, set is unordered and unique elements
# 2. try to get an element from dict, use get()
# 3. use None, same as Nil or null, or nullptr in c++
# 4. use += num to increase values
# 5. use [a, b] to return values directly

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = {} # {item, list index}
        idx = 0
        for i in nums:
            if result.get(target - i) != None:
                return [idx, result[target-i]]
            else:
                result[i] = idx
            idx += 1
        
        return None