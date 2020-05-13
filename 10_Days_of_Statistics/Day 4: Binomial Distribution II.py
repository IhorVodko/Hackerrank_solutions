#problem: https://www.hackerrank.com/challenges/s10-binomial-distribution-2/problem?h_r=next-challenge&h_v=zen


from itertools import combinations

per_rejected = 0.12
batch_size = 10

def bin_dist(num_rejected, per_rejected = 0.12):
    solution = len([*combinations(range(10), num_rejected)])\
        * (per_rejected ** num_rejected)\
        * ((1-per_rejected) ** (10 - num_rejected)) 
    return solution

solution1 = 0 
for num_rejected in range(3):
    bin_dist(num_rejected)
    solution1 += bin_dist(num_rejected)
    
solution2 = 0 
for num_rejected in range(2, 11):
    bin_dist(num_rejected)
    solution2 += bin_dist(num_rejected)
    
print(round(solution1, 3), round(solution2, 3), sep = "\n")
