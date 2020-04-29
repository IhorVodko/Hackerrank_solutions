#Problem: https://www.hackerrank.com/challenges/word-order/problem
#Score    50


from collections import Counter

all_w = Counter(input() for _ in range(int(input())))
res = all_w.values()
length = len(res)
# print([input() for _ in range(int(input()))])

print(length)
print(*res)
