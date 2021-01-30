#problem: https://www.hackerrank.com/challenges/np-concatenate/problem

import numpy as np

m, n, p = map(int, input().split())

array1 = np.array([input().split() for _ in range(m)], int)
array2 = np.array([input().split() for _ in range(n)], int)

print(np.concatenate((array1, array2), axis = 0))
