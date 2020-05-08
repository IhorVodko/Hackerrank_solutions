#Problem: https://www.hackerrank.com/challenges/s10-mcq-2/problem


from itertools import product

dice = [*product(range(1, 7), repeat=2)]
count_all_sums = len(dice)
count_6_sums = sum([1 for x in dice if (x[0] != x[1]) and (x[0] + x[1] == 6)])
solution = count_6_sums / count_all_sums

print(round(solution, 4))
