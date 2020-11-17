#Problem: https://www.hackerrank.com/challenges/introduction-to-regex/problem


import re 

for _ in range(int(input())):

    print(bool(re.match( (r'^[+-]?\d*\.\d+$'), input())) )
 
