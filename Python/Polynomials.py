#problem: https://www.hackerrank.com/challenges/np-polynomials/problem


import numpy as np


print(np.polyval(list(map(float, input().split())), float(input())))
