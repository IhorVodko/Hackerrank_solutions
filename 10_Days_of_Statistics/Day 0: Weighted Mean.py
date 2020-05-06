#Problem: https://www.hackerrank.com/challenges/s10-weighted-mean/problem?h_r=next-challenge&h_v=zen


count = int(input())
nums = [int(x) for x in input().strip().split()]
weights = [int(x) for x in input().strip().split()]

solution = (sum([x[0]*x[1] for x in [*zip(nums, weights)]])) / sum(weights)

print(round(solution, 1))
