#problem: https://www.hackerrank.com/challenges/maximize-it/problem


from itertools import product

k, m = [int(x) for x in input().split()]
genOfLists = (list(map(int, input().split()))[1:] for _ in range(k))
results = map(lambda list_: sum(num*num for num in list_)%m, product(*genOfLists))
print(max(results))
