#problem: https://www.hackerrank.com/challenges/np-min-and-max/problem


import numpy as np


myArray = np.array([input().split() for _ in range(int(input().split()[0]))], int)
minArray = np.min(myArray, axis = 1)
print(np.max(minArray))
