#Problem: https://www.hackerrank.com/challenges/compress-the-string/problem


from itertools import groupby

arr = [*map(int, list(input()))]

res = []
for k, g in groupby(arr):
    res.append(((len(list(g)), k)))
print(*res)
