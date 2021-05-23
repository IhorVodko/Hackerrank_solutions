#problem: https://www.hackerrank.com/challenges/validating-credit-card-number/problem


import re

pattern = re.compile(r"^(?!.*(\d)(-?\1){3})[456]\d{3}(?:-?\d{4}){3}$")

for _ in range(int(input())):
    if re.match(pattern, input()):
        print("Valid")
    else:
        print("Invalid")
