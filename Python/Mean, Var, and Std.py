#problem: https://www.hackerrank.com/challenges/np-mean-var-and-std/forum


import numpy as np


myArray = np.array([input().split() for _ in range(int(input().split()[0]))], int)
myMean = np.mean(myArray, axis = 1)
myVar = np.var(myArray, axis = 0)
myStd = round(np.std(myArray), 11)
print(*[myMean, myVar, myStd], sep = '\n')
