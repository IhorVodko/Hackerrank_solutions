#Problem: https://www.hackerrank.com/challenges/s10-binomial-distribution-1/problem


from itertools import combinations

prob_boy = 1.09 / (1.09 + 1)
prob_girl = 1 / (1.09 + 1)

solution = 0
for num_boys in range(3, 7): 
    bin_dist = \
        len([*combinations(range(6), num_boys)])\
        * (prob_boy ** num_boys) * (prob_girl ** (6 - num_boys)) 
    solution += bin_dist 
print(round(solution, 3))
