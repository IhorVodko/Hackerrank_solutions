#Problem: https://www.hackerrank.com/challenges/s10-mcq-3/problem


from itertools import product, combinations

X = ['r']*4 + ['b']*3
Y = ['r']*5 + ['b']*4
Z = ['r']*4 + ['b']*4
take_sample = ['r']*2 + ['b']

take_all = [*permutations(take_one, 3)]
all_comb = [*product(X,Y,Z)]

take_count = sum([1 for x in all_comb if x in take_all])
solution = take_count / len(all_comb)

print(round(solution, 4))
