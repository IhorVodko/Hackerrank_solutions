#Problem: https://www.hackerrank.com/challenges/s10-quartiles/problem


quant = int(input())
nums = sorted([int(x) for x in input().strip().split()])

def median(nums):
        l = len(nums)
        if l % 2 == 0:
            m = (nums[l//2] + nums[(l//2)-1]) / 2
        else: 
            m = nums[l//2]
        return int(m)
    
q1 = median(nums[:(quant//2)])
q2 = median(nums)
q3 = median(nums[-(quant//2):])

print(q1, q2, q3, sep="\n")
