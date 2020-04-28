#Problem https://www.hackerrank.com/challenges/find-angle/problem
#Score   10


import math

l1 = int(input())
l2 = int(input())
print(''.join([str(int(round(math.degrees(math.atan(l1/l2)), 0))), '°']))
