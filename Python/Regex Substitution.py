#problem: https://www.hackerrank.com/challenges/re-sub-regex-substitution/problem


# Enter your code here. Read input from STDIN. Print output to STDOUT
import re

for _ in range(int(input())):
    print(re.sub(r"(?<= )(&&|\|\|)(?= )", lambda x: "and" if x.group() == "&&" 
        else "or", input()))
