#Problem: https://www.hackerrank.com/challenges/no-idea/problem
#Score:   50


from collections import Counter

l1 = input()
n = [*map(int, input().split())]
a = [*map(int, input().split())]
b = [*map(int, input().split())]

all_num = Counter(n)
res = sum([all_num[i] for i in a]) - sum([all_num[j] for j in b])
print(res)
