#problem: https://www.hackerrank.com/challenges/np-eye-and-identity/problem

import numpy as np
np.set_printoptions(sign = ' ')


print(np.eye(*map(int, input().split())))
