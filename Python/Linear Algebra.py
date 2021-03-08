#problem: https://www.hackerrank.com/challenges/np-linear-algebra/problem


import numpy as np


myArr = np.array([input().split() for _ in range(int(input()))], float)
print(round(np.linalg.det(myArr), 2))
