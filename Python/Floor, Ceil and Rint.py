#problem: https://www.hackerrank.com/challenges/floor-ceil-and-rint/problem


import numpy as np
np.set_printoptions(legacy='1.13')


my_array = np.array(input().split(), float)
print(*(fun(my_array) for fun in [np.floor, np.ceil, np.rint]), sep = '\n')
