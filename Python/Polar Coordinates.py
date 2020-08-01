#Problem: https://www.hackerrank.com/challenges/polar-coordinates/problem


import cmath

num = input().strip()
print(*[abs(complex(num)), cmath.phase(complex(num))], sep = '\n')
