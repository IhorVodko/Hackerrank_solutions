#Problem: https://www.hackerrank.com/challenges/between-two-sets/problem


def getTotalX(a, b):
    numbers1 = []
    numbers2 = []
    for i in range(max(a), min(b)+1):
        if all([i%j==0 for j in a]):
            numbers1.append(i)
    for k in numbers1:
        if all([j%k==0 for j in b]):
            numbers2.append(k)
    return len(numbers2)
