#problem: https://www.hackerrank.com/challenges/np-sum-and-prod/problem


import numpy as np


my_arr = np.array([input().split() for _ in range(int(input()[0]))], int)
print(np.prod(np.sum(my_arr, axis=0)))
