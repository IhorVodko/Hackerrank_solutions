#Problem: https://www.hackerrank.com/challenges/s10-standard-deviation/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen


count = int(input())
arr = [int(x) for x in input().strip().split()]

mean_ = sum(arr) / count
solution = (sum([(x - mean_)**2 for x in arr]) / count) ** 0.5

print(round(solution, 1))
