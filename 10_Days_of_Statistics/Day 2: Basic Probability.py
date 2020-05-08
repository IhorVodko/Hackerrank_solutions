#Problem: https://www.hackerrank.com/challenges/s10-mcq-1/problem


from itertools import product

dice = [*product(range(1, 7), repeat=2)]
count_all_sums = len(dice)
count_9_sums = sum([sum(x) <= 9 for x in dice])
solution = count_9_sums / count_all_sums

print(round(solution, 4))
