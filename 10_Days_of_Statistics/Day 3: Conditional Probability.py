#Problem: https://www.hackerrank.com/challenges/s10-mcq-4/problem

from itertools import product

girl = '0'
boy = '1'
family = [girl, boy]
family_all = [*product(family, repeat = 2)]
family_both_boys = [x for x in family_all if x[0]=='1' and x[1] == '1']
family_one_boy = [x for x in family_all if x[0]=='1' or x[1] == '1']
solution = len(family_both_boys) / len(family_one_boy)
print(round(solution, 4))
