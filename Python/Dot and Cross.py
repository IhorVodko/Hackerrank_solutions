#problem: https://www.hackerrank.com/challenges/np-dot-and-cross/problem


import numpy as np

dimension = int(input())
matrixA = np.array([input().split() for _ in range(dimension)], int)
matrixB = np.array([input().split() for _ in range(dimension)], int)
print(np.matmul(matrixA, matrixB))
