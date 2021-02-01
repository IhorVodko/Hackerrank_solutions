#problem: https://www.hackerrank.com/challenges/np-zeros-and-ones/problem


import numpy as np

numOfElementsAndDimensions = tuple(map(int, input().split()))
print(np.zeros(numOfElementsAndDimensions, dtype = np.int))
print(np.ones(numOfElementsAndDimensions, dtype = np.int))
