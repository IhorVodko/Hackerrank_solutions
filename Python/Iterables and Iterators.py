#Problem: https://www.hackerrank.com/challenges/iterables-and-iterators/problem


from itertools import combinations

length = int(input())
string = input().split()
k = int(input())

comb = [*combinations(string, k)]
with_a =  sum([1 for x in comb if 'a' in x]) 
res = round((with_a/len(comb)), 4)

print(res)
