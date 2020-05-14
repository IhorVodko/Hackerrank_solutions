#Problem: https://www.hackerrank.com/challenges/s10-geometric-distribution-1/problem


prob_defect = 1/3
inspection_th = 5

solution = (prob_defect ** 1) * ((1-prob_defect) ** (inspection_th - 1))

print(round(solution, 3))
