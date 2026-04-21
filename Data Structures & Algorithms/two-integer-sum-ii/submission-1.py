class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l=len(numbers)
        i=0
        while i<l:
            if numbers[i]+numbers[l-1]==target:
                return [i+1,l]
            elif numbers[i]+numbers[l-1]<target:
                i=i+1
            else:
                l=l-1