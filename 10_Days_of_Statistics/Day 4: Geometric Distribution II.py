#Problem: https://www.hackerrank.com/challenges/s10-geometric-distribution-2/problem


prob_defect = 1/3
inspection_th = 5

solution = 0
for i in range(1, inspection_th + 1):
    solution += ((1 - prob_defect) ** (i - 1)) * prob_defect
    
print(round(solution, 3))
