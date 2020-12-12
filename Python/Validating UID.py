#Problem: https://www.hackerrank.com/challenges/validating-uid/problem


import re


pattern = r"^(?!.*(.).*\1)(?=(?:.*[A-Z]){2,})(?=(?:.*\d){3,})[a-zA-Z0-9]{10}$" 
[print('Valid') if re.match(pattern, input()) else print('Invalid') for test_str \
    in range(int(input()))]
