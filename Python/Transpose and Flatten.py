#problem: https://www.hackerrank.com/challenges/np-transpose-and-flatten/problem


import numpy as np

myArray = np.array([input().split() for _ in range(int(input().split()[0]))], int)
print(myArray.transpose(), myArray.flatten(), sep = '\n')
