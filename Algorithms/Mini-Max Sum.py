#Problem: https://www.hackerrank.com/challenges/mini-max-sum/problem


from itertools import combinations

def miniMaxSum(arr):
    sums = [] 
    for i in combinations(arr, 4):
        sum_ = sum(i)
        sums.append(sum_)
    minn = min(sums)
    maxx = max(sums)
    print(minn, maxx)
