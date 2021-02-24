#problem: https://www.hackerrank.com/challenges/np-inner-and-outer/problem


import numpy as np

arrA = np.array(input().split(), int)
arrB = np.array(input().split(), int)
print(*[np.inner(arrA, arrB), np.outer(arrA, arrB)], sep = '\n')
