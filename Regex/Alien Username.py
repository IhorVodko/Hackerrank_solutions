#problem: https://www.hackerrank.com/challenges/alien-username/problem


import re

for _ in range(int(input())):
    test = input()
    pattern = '^[._]\d+[a-zA-Z]*[_]?$'
    result = re.match(pattern, test)
    if result:
        print('VALID')
    else:
        print('INVALID')

