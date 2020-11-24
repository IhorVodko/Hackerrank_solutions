#Problem: https://www.hackerrank.com/challenges/validating-the-phone-number/problem


import re

for _ in range(int(input())):
    print("YES" if re.match('^[789]\d{9}$', input().strip()) else "NO")
