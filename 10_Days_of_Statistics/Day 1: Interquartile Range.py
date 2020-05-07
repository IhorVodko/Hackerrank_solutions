#Problem: https://www.hackerrank.com/challenges/s10-interquartile-range/problem


quant = int(input())
nums = [int(x) for x in input().strip().split()]
freq = [int(x) for x in input().strip().split()]

list_nested = [[x[0]]*x[1] for x in [*zip(nums, freq)]]
list_ = [item for sublist in list_nested for item in sublist]

nums = sorted(list_)

def median(nums):
        l = len(nums)
        if l % 2 == 0:
            m = (nums[l//2] + nums[(l//2)-1]) / 2
        else: 
            m = nums[l//2]
        return m
    
q1 = median(nums[:(len(nums)//2)])
q3 = median(nums[-(len(nums)//2):])

solution = q3-q1

print(round(solution, 1))
