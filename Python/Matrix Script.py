#problem: https://www.hackerrank.com/challenges/matrix-script/problem


#!/bin/python3

import math
import os
import random
import re
import sys




first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)
       
almost_decoded_str = ''.join([row[index] for index in range(m) for row in matrix])
decoded_str = re.sub(r'(?<=[a-zA-Z0-9])[!@#\$%& ]+(?=[a-zA-Z0-9])', ' ',
                        almost_decoded_str)
print(decoded_str)
