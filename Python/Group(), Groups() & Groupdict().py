#Problem: https://www.hackerrank.com/challenges/re-group-groups/problem


import re

match = re.search(r'([a-zA-Z0-9])\1+', input().strip())
print(match.group(1) if match else -1)
